
/*
    Tamaño de la pantalla 240x320 pixeles
*/

// Librería para el protocolo de datos seriales síncronos SPI (Serial Peripheral Interface)
#include "SPI.h"
// Librería para gráficos, con un conjunto de primitivas: puntos, líneas, círculos, etc.
#include "Adafruit_GFX.h" 
// Librería para el display LCD TFT (Thin Film Transistor) 
#include "Adafruit_ILI9341.h"

// Include Sprites
#include "Sprite.h"

// Se definen los pines para la conexión entre el Arduino Mega y el TFT LCD ILI9341
#define TFT_DC 7
#define TFT_CS 6
#define TFT_MOSI 11
#define TFT_CLK 13
#define TFT_RST 10
#define TFT_MISO 12

#define botonRight 18
#define botonLeft 19
#define attackButton 20
#define MOVE_DELAY 30 // Tiempo entre movimientos continuos (ms)
#define MAX_BULLETS 9
// Declaración de variables globales
bool isMovingRight = false;
bool isMovingLeft = false;


const int XMAX = 240; // Alto del display
const int YMAX = 320; // Ancho del display
const int buzzerPin = 5; // Pin donde conectaste el buzzer

int playerX = 0; // Posición X del jugador
int playerY = YMAX - 32; // Posición Y del jugador
int enemySpeed = 15;     // Velocidad del enemigo
int enemyX = 0; // Posición X del enemigo
int enemyY = 5; // Posición Y del enemigo (cerca del límite superior)
int playerFrame = 0; // Fotograma del jugador
int enemyFrame = 0; // Fotograma del enemigo
int bulletX = -1; // Posición inicial fuera de la pantalla
int bulletY = -1; // Posición inicial fuera de la pantalla
int remainingBullets = MAX_BULLETS; // Número de balas disponibles al inicio
bool bulletActive = false; // Indica si hay un proyectil en vuelo
bool shootButtonPrevState = LOW;
bool enemyDefeated = false;
bool buzzerActive = false; // Bandera para controlar el buzzer
unsigned long lastPlayerUpdate = 0; // Tiempo de la última actualización del jugador
unsigned long lastEnemyUpdate = 0; // Tiempo de la última actualización del enemigo
unsigned long animationDelay = 10; // Tiempo entre cambios de fotograma
const uint8_t UP = 0;
const uint8_t DOWN = 1;
const uint8_t RIGHT = 2;
const uint8_t LEFT = 3;


// Se instancia el objeto screen del tipo Adafruit_ILI9341 cuyos
// parámetros corresponden a los pines de conexión definidos anteriormente
Adafruit_ILI9341 screen = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

GFXcanvas1 canvas(360, 36);

// Declaración de funciones
void animatePlayer(void);
void animateEnemy(void);
void moverPlayer(uint8_t direccion);
void moverPlayerDerecha(void);
void moverPlayerIzquierda(void);
void shootBullet();
void checkCollision();
void updateBullets();
void animateExplosion();
void waitForRestart();
void resetGame();



struct Bullet {
    int x;
    int y;
    bool active; // Si la bala está activa o no
};
Bullet bullets[MAX_BULLETS];

// Configuración 
void setup() {

    Serial.begin(9600);
    Serial.println("Serial inicializado");


    // Configura SPI a máxima velocidad soportada por la pantalla
    SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0)); // 40 MHz

    // Se agregan interrupciones externas
    attachInterrupt(digitalPinToInterrupt(botonRight), moverPlayerDerecha, HIGH);
    attachInterrupt(digitalPinToInterrupt(botonLeft), moverPlayerIzquierda, HIGH);

    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = false; // Al principio todas las balas están inactivas
    }

    // Configuracion de la pantalla
    screen.begin(); // Inicializacion
    screen.fillScreen(ILI9341_BLACK); // Pinta la pantalla de negro

    sei();      
}


// Lazo infinito, codigo que se repite constantemente
void loop() {
    unsigned long currentTime = millis();
    static unsigned long lastEnemyUpdate = 0;

    // Animación del jugador
    if (currentTime - lastPlayerUpdate > animationDelay) {
        animatePlayer();
        lastPlayerUpdate = currentTime;
    }

    // Animación del enemigo
    if (currentTime - lastEnemyUpdate > animationDelay) {
        animateEnemy();
        lastEnemyUpdate = currentTime;
    }
    updateBullets();
    checkCollision();

    bool shootButtonState = digitalRead(attackButton);

    // Detecta una pulsación nueva (transición de LOW a HIGH)
    if (shootButtonState == HIGH && shootButtonPrevState == LOW) {
        shootBullet(); // Dispara una bala
    }
     // Actualiza el estado previo del botón
    shootButtonPrevState = shootButtonState;
    
    if (remainingBullets == 0 && !enemyDefeated) {
        // Mostrar mensaje de derrota
        screen.fillScreen(ILI9341_BLACK);
        screen.setCursor(20, YMAX / 2 - 10);
        screen.setTextColor(ILI9341_RED);
        screen.setTextSize(5);
        screen.println("U LOSE");

        tone(buzzerPin, 400, 500); // Tono grave para derrota
        delay(500);
        noTone(buzzerPin);

        waitForRestart(); // Espera a reiniciar el juego
        return; // Salir del bucle principal
    }

    delay(30); // Control de la velocidad general del juego
}


void animatePlayer() {
    static int prevPlayerX = 0;
    static int prevPlayerY = 0;

    noInterrupts(); 
    // Borra el fotograma anterior
    screen.fillRect(prevPlayerX - 1, prevPlayerY - 1, 40, 40, ILI9341_BLACK);

    // Dibuja el nuevo fotograma
    screen.drawBitmap(playerX, playerY, Player[playerFrame], 32, 32, ILI9341_WHITE);

    // Actualiza las posiciones anteriores
    prevPlayerX = playerX;
    prevPlayerY = playerY;

    if (playerX < 0) playerX = 0;
    if (playerX > XMAX - 32) playerX = XMAX - 32; // Ajusta para el tamaño del sprite

    interrupts();
    // Cambia el fotograma
    playerFrame = (playerFrame + 1) % 3;
}

void animateEnemy() {
    static int prevX = 0; // Posición previa del enemigo en X

    noInterrupts(); 
    // Borra el fotograma previo
    screen.fillRect(prevX, enemyY, 40, 40, ILI9341_BLACK);

    // Dibuja el fotograma actual del enemigo
    screen.drawBitmap(enemyX, enemyY, Enemy[enemyFrame], 32, 32, ILI9341_YELLOW);

    // Actualiza la posición previa
    prevX = enemyX;

    // Mueve al enemigo
    enemyX += enemySpeed;

    // Rebote en los límites de la pantalla
    if (enemyX >= (XMAX - 32) || enemyX <= 0) {
        enemySpeed = -enemySpeed; // Cambia la dirección
    }
    
    interrupts();
    // Actualiza el fotograma del enemigo
    enemyFrame++;
    if (enemyFrame == 3) {
        enemyFrame = 0; // Vuelve al primer fotograma
    }
}

// Función que atienda la interrupción
void moverPlayerDerecha() {
    if(digitalRead(botonRight) == HIGH) {
        Serial.println("Boton RIGHT");
        if (!buzzerActive) {
            tone(buzzerPin, 90, 90); // Tono agudo al mover
            buzzerActive = true;        // Activar la bandera
        }
        moverPlayer(RIGHT);
    } else {
        buzzerActive = false; // Reinicia la bandera cuando se deja de presionar
    
    }    
}
void moverPlayerIzquierda() {
    delay(50);
    if(digitalRead(botonLeft) == HIGH) {
        Serial.println("Boton LEFT");
        if (!buzzerActive) {
            tone(buzzerPin, 90, 90); // Tono agudo al mover
            buzzerActive = true;        // Activar la bandera
        }
        moverPlayer(LEFT);
    } else {
        buzzerActive = false; // Reinicia la bandera cuando se deja de presionar
    }
}
// Mueve el jugador
void moverPlayer(uint8_t direccion) {
    
    uint8_t delta = 10;
    switch (direccion)
    {
    case 0:
        playerY = playerY - delta;
        break;
    case 1:
        playerY = playerY + delta;
        break;
    case 2:
        playerX = playerX + delta;
        break;
    case 3:
        playerX = playerX - delta;
        break;
    }
}
void updateBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {

            noInterrupts();
            // Borra la posición anterior de la bala
            screen.fillRect(bullets[i].x, bullets[i].y, 4, 8, ILI9341_BLACK);

            // Mueve la bala hacia arriba
            bullets[i].y -= 30;

            // Si la bala está dentro de los límites, redibújala
            if (bullets[i].y > 0) {
                screen.fillRect(bullets[i].x, bullets[i].y, 4, 8, ILI9341_WHITE);
            } else {
                // Si la bala sale de la pantalla, desactívala
                bullets[i].active = false;
            }
            interrupts();
        }
    }
}

void shootBullet() {
    if (remainingBullets > 0) { // Solo dispara si hay balas disponibles
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].active) {
                bullets[i].x = playerX + 14;
                bullets[i].y = playerY - 8;
                bullets[i].active = true;
                remainingBullets--; // Reduce las balas disponibles
                Serial.println("¡Disparo!");
                Serial.print("Balas restantes: ");
                Serial.println(remainingBullets - 1);
                tone(buzzerPin, 2000, 100); // Tono breve al disparar
                break;
            }
        }
    }
}

void checkCollision() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active && 
            bullets[i].x >= enemyX && bullets[i].x <= enemyX + 32 && 
            bullets[i].y >= enemyY && bullets[i].y <= enemyY + 32) {
            
            // Desactiva la bala
            bullets[i].active = false;
            enemyDefeated = true; // Marca al enemigo como derrotado
            // Detener la animación del enemigo
            animateExplosion(); // Animación de explosión

            // Mostrar "Juego terminado"
            screen.fillScreen(ILI9341_BLACK); // Limpia la pantalla
            screen.setCursor(50, YMAX / 2 - 10);
            screen.setTextColor(ILI9341_RED);
            screen.setTextSize(5);
            screen.println("U WIN");

            tone(buzzerPin, 1500, 100); // Secuencia para victoria
            delay(200);
            tone(buzzerPin, 2000, 100);
            delay(200);
            noTone(buzzerPin);

            // Esperar a que se presione un botón para reiniciar
            waitForRestart();

            return; // Sale de la función
        }
    }
}

void animateExplosion() {
    for (int i = 0; i < 3; i++) { // Asume 3 fotogramas de la explosión
        screen.fillRect(enemyX, enemyY, 40, 40, ILI9341_BLACK); // Borra el sprite previo
        screen.drawBitmap(enemyX, enemyY, Explosion[i], 32, 32, ILI9341_RED); // Dibuja el fotograma de explosión
        tone(buzzerPin, 800, 200); // Tono intermitente para la explosión
        delay(200);
        noTone(buzzerPin); // Pausa
        delay(100); // Pausa entre fotogramas
    }
    screen.fillRect(enemyX, enemyY, 40, 40, ILI9341_BLACK); // Limpia al final de la animación
}

void waitForRestart() {
    while (true) {
        if (digitalRead(botonRight) == HIGH || digitalRead(botonLeft) == HIGH || digitalRead(attackButton) == HIGH) {
            // Reinicia el juego
            resetGame();
            break;
        }
        delay(100); // Pequeña pausa para evitar rebotes
    }
}
void resetGame() {
    playerX = 0;
    playerY = YMAX - 32;
    enemyX = 0;
    enemyY = 5;
    enemySpeed = 10;
    playerFrame = 0;
    enemyFrame = 0;
    remainingBullets = MAX_BULLETS; // Restablece las balas
    enemyDefeated = false; // Marca al enemigo como no derrotado
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = false;
    }
    screen.fillScreen(ILI9341_BLACK);
}