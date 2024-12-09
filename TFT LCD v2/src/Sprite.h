#ifndef Sprite_h
#define Sprite_h

#include <avr/pgmspace.h>

const unsigned char Player[3] [128] PROGMEM = {
	// '83288145-vector-píxel-nave-espac, 32x32px
	0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 
	0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1c, 0x78, 0x00, 
	0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 
	0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x0e, 0x1f, 0xf8, 0x70, 0x1e, 0x1f, 0xf8, 0x70, 
	0x1e, 0x1f, 0xf8, 0x70, 0x1e, 0x3f, 0xf8, 0x78, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xf8, 0x7f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfe, 0x1f, 0xf8, 0x7f, 
	0xfe, 0x1f, 0xf8, 0x7f, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 
	
	// 'depositphotos_677205220-stock-il, 32x32px
	0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x07, 0xf0, 0x00, 
	0x00, 0x0f, 0xf0, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00, 
	0x00, 0x3f, 0xfc, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x80, 
	0x03, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf8, 
	0x1f, 0xff, 0xff, 0xf8, 0x3f, 0x1f, 0xf8, 0xfc, 0x7e, 0x1f, 0xf8, 0x7e, 0xfc, 0x1f, 0xf8, 0x3f, 
	0xfc, 0x1f, 0xf8, 0x3f, 0xfc, 0x1f, 0xf8, 0x3f, 0xfc, 0x1f, 0xf8, 0x3f, 0xfc, 0x1f, 0xf8, 0x3f, 
	0xfc, 0x1f, 0xf8, 0x3f, 0xfc, 0x0f, 0xf0, 0x3f, 0xfc, 0x0f, 0xf0, 0x3f, 0x00, 0x0f, 0xf0, 0x00, 
	0x00, 0x07, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00,

	// '83288145-vector-píxel-nave-espac, 32x32px
	0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 
	0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1c, 0x78, 0x00, 
	0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 
	0x00, 0x1c, 0x38, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x0e, 0x1f, 0xf8, 0x70, 0x1e, 0x1f, 0xf8, 0x70, 
	0x1e, 0x1f, 0xf8, 0x70, 0x1e, 0x3f, 0xf8, 0x78, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xf8, 0x7f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfe, 0x1f, 0xf8, 0x7f, 
	0xfe, 0x1f, 0xf8, 0x7f, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00 
};
const unsigned char Enemy[3] [128] PROGMEM = {
	// 'human-skull-icon-pixel-art-260nw (1), 32x32px

{	0x03, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf8, 
	0x1f, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xfc, 0x73, 0xff, 0xff, 0xce, 
	0x7b, 0xff, 0xff, 0x9e, 0xfb, 0xff, 0xff, 0x9f, 0xfb, 0xff, 0xff, 0x9f, 0xfb, 0xff, 0xff, 0x9f, 
	0xfb, 0xff, 0xff, 0xdf, 0xf7, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xf7, 0xdf, 0xff, 0xff, 0xfb, 
	0xf8, 0x0f, 0xe0, 0x3f, 0xf8, 0x07, 0xc0, 0x1f, 0x70, 0x03, 0xc0, 0x0e, 0x30, 0x07, 0xc0, 0x0e, 
	0x30, 0x0f, 0xf0, 0x0c, 0x30, 0x1f, 0xf8, 0x0c, 0x3c, 0x7e, 0x7c, 0x3c, 0x7f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfe, 0x7f, 0xfc, 0x3f, 0xfe, 0x7f, 0xfd, 0x3f, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 
	0x38, 0xff, 0xff, 0x1c, 0x00, 0xff, 0xff, 0x00, 0x00, 0xee, 0x67, 0x00, 0x00, 0xee, 0x67, 0x00
}, 
	// 'pixel-art-human-skull-illustrati (1), 32x32px

{	0x03, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf8, 
	0x3f, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xe3, 0xff, 0xff, 0x87, 0xe1, 0xff, 0xff, 0x07, 0xc0, 0xff, 
	0xfe, 0x07, 0xe0, 0x7f, 0xfe, 0x07, 0xe0, 0x7f, 0xfe, 0x03, 0xe0, 0x7f, 0xfe, 0x07, 0xf0, 0x3f, 
	0xfe, 0x0e, 0x78, 0x3f, 0x7f, 0xfc, 0x3f, 0xfe, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xf8, 0x1f, 0xfc, 
	0x1f, 0xf9, 0x9f, 0xf8, 0x07, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0x80, 
	0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 0x01, 0xef, 0xf7, 0x80, 
	0x01, 0xef, 0xf7, 0x80, 0x00, 0xef, 0x77, 0x00, 0x00, 0x6e, 0x76, 0x00, 0x00, 0x0e, 0x70, 0x00
}, 
	// 'c78894b0f71844828de51c72f85eb62b (2), 32x32px

{	0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 
	0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 
	0xff, 0xff, 0xff, 0x3e, 0xf8, 0x3f, 0xfe, 0x1e, 0x78, 0x0f, 0xe0, 0x1e, 0x38, 0x07, 0xc0, 0x1c, 
	0x3c, 0x03, 0xc0, 0x3c, 0x0f, 0x87, 0xc0, 0xf0, 0x07, 0xff, 0xff, 0xe0, 0x03, 0xfe, 0x7f, 0xc0, 
	0x03, 0xfe, 0x7f, 0x80, 0x01, 0xfe, 0x7f, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0x00, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xff, 0x00, 0x00, 0xef, 0xf7, 0x00, 0x00, 0x6d, 0xb6, 0x00, 0x00, 0x4d, 0xb6, 0x00
}
};
const unsigned char Explosion[3][128] PROGMEM = {

	// '1-fotor-bg-remover-2024120420745 (1), 32x32px

{	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x60, 0x40, 0x00, 0x1c, 0xe1, 0xc0, 0x00, 0x1f, 0xf7, 0xc0, 
	0x03, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xf0, 
	0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0x80, 
	0x03, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xf0, 
	0x03, 0xff, 0xff, 0xe0, 0x01, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x80, 
	0x03, 0x1f, 0xff, 0x80, 0x00, 0x19, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x40, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}, 
	// '2-fotor-bg-remover-202412042083 (1), 32x32px

{	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x7e, 0x10, 0x00, 
	0x01, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xfd, 0x80, 0x0f, 0xff, 0xfe, 0x00, 
	0x0f, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0x80, 0x2f, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0x80, 
	0x0f, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xc0, 
	0x0f, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xfb, 0x00, 
	0x0d, 0x0f, 0xf0, 0x00, 0x00, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}, 
	// '3-fotor-bg-remover-2024120420818 (1), 32x32px

{	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x03, 0x98, 0x00, 
	0x00, 0x1f, 0xf8, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x3f, 0xfc, 0x00, 
	0x00, 0x3f, 0xfc, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x1f, 0xf0, 0x00, 
	0x00, 0x3f, 0xb0, 0x00, 0x00, 0x31, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}
};

#endif