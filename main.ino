

/* Tamagero
    by Kurt Butler

    Yes, this is a Tamagotchi clone. Made as an example project
    on the Arduboy platform.
*/

#include <Arduboy2.h>
Arduboy2 ab; //give this dude an analysis


//const uint8_t PROGMEM  tama0[] = { //16x16 px
//0xFF, 0xFF, 0xCF, 0xCF, 0xB7, 0xB7, 0xA8, 0x57, 
//0xAF, 0xDB, 0xAF, 0xDB, 0x7F, 0xFD, 0x00, 0x05, 
//0x7F, 0xFD, 0x80, 0x03, 0xEF, 0xEF, 0xD8, 0xF7, 
//0xD7, 0x77, 0xD7, 0x7B, 0xD7, 0x7B, 0xE0, 0x07};

//const uint8_t ntama0[] PROGMEM = { //16x16px
//0x00, 0x00, 0x30, 0x30, 0x48, 0x48, 0x57, 0xA8, 
//0x50, 0x24, 0x50, 0x24, 0x80, 0x02, 0xFF, 0xFA, 
//0x80, 0x02, 0x7F, 0xFC, 0x10, 0x10, 0x27, 0x08, 
//0x28, 0x88, 0x28, 0x84, 0x28, 0x84, 0x1F, 0xF8};

// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>
//                    TAMAGERO SPRITES
// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>

//const unsigned int PROGMEM ntamablock[] = { //25  16x16px blocks
const uint8_t ntamablock[] PROGMEM = { //16x16px
0x00, 0x00, 0x30, 0x30, 0x48, 0x48, 0x57, 0xA8, 
0x50, 0x24, 0x50, 0x24, 0x80, 0x02, 0xFF, 0xFA, 
0x80, 0x02, 0x7F, 0xFC, 0x10, 0x10, 0x27, 0x08, 
0x28, 0x88, 0x28, 0x84, 0x28, 0x84, 0x1F, 0xF8,
0x03, 0xF0, 0x06, 0x10, 0x04, 0x00, 0x3F, 0x7C, 
0x37, 0xEC, 0x03, 0x20, 0x23, 0x24, 0x7F, 0x3E, 
0x07, 0xE0, 0x3E, 0x1C, 0x5E, 0xDA, 0x4C, 0x1A, 
0x38, 0x0C, 0x19, 0x28, 0x1C, 0x18, 0x0F, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x12, 
0x48, 0xCA, 0x47, 0x29, 0x81, 0x25, 0xA0, 0x25, 
0x84, 0xB5, 0x8A, 0x2D, 0x40, 0x02, 0x38, 0x81, 
0x17, 0x49, 0x20, 0x36, 0x26, 0x20, 0x19, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x12, 
0x48, 0xCA, 0x47, 0x2F, 0x86, 0x27, 0xA0, 0x27, 
0x84, 0xB5, 0xEA, 0x3D, 0x40, 0xFE, 0x38, 0x79, 
0x1F, 0xF9, 0x2E, 0x36, 0x26, 0x20, 0x19, 0xC0,
0x1F, 0xD8, 0xBF, 0xFC, 0x7F, 0xFE, 0xE4, 0x1F, 
0xC0, 0x0F, 0x90, 0x27, 0xB8, 0x77, 0x90, 0x27, 
0x87, 0x07, 0x40, 0x09, 0x3F, 0xF0, 0x8F, 0xE0, 
0x1F, 0xC0, 0x3F, 0xF4, 0x1F, 0xF9, 0x3F, 0xFF,
0x08, 0x80, 0x18, 0xC0, 0x28, 0xA0, 0x28, 0xA0, 
0x4F, 0x10, 0x20, 0x20, 0x7F, 0xF0, 0x20, 0x20, 
0x26, 0x20, 0x10, 0x10, 0x0F, 0x90, 0x04, 0x18, 
0x04, 0x0C, 0x05, 0xA4, 0x09, 0x24, 0x0F, 0xFC,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 
0x01, 0x80, 0x1B, 0xDC, 0x25, 0xA2, 0x40, 0x81, 
0x58, 0x19, 0x52, 0x49, 0x5B, 0xD9, 0x41, 0x41, 
0x60, 0x13, 0x76, 0x37, 0x3F, 0xFE, 0x1F, 0xFC,
0x01, 0xEF, 0x00, 0xFE, 0x00, 0x7C, 0x00, 0x3C, 
0x00, 0x1E, 0x3F, 0xDF, 0x7F, 0xFF, 0xC0, 0x7F, 
0x80, 0x3F, 0x80, 0xB3, 0xA0, 0x31, 0x84, 0x37, 
0x9B, 0x3E, 0xC0, 0x7C, 0xFF, 0xF8, 0x7F, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x38, 
0x13, 0xE4, 0x17, 0xF4, 0x1F, 0xFC, 0x0D, 0xB8, 
0x0E, 0x78, 0x07, 0xF0, 0x1E, 0x78, 0x1C, 0x38, 
0x0C, 0x30, 0x06, 0x70, 0x0F, 0xF0, 0x0E, 0x70,
0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x44, 
0x00, 0x40, 0x15, 0xD0, 0xB7, 0xFA, 0x3F, 0xFE, 
0x7F, 0xFE, 0xC0, 0xFF, 0x80, 0x7F, 0xE1, 0xFF, 
0x80, 0x7F, 0x9E, 0x7F, 0x40, 0xFE, 0x3F, 0xFC,
0x0F, 0xC0, 0x10, 0x20, 0x20, 0x10, 0x20, 0x08, 
0x38, 0xD0, 0x20, 0x10, 0x27, 0x10, 0x22, 0x10, 
0x2D, 0x90, 0x20, 0x16, 0x20, 0x19, 0x20, 0x11, 
0x20, 0x12, 0x27, 0x84, 0x24, 0x98, 0x18, 0x60,
0x01, 0x80, 0x02, 0x40, 0x04, 0x20, 0x08, 0x10, 
0x13, 0xC8, 0x35, 0xAC, 0x67, 0xE6, 0xB7, 0xED, 
0xB7, 0xED, 0x66, 0x66, 0x23, 0xC4, 0x10, 0x08, 
0x3C, 0x3C, 0x7F, 0xFE, 0x0F, 0xF0, 0x1F, 0xF8,
0x1D, 0xE0, 0x22, 0x10, 0x5E, 0xD0, 0x56, 0x90, 
0x4C, 0x60, 0x44, 0x00, 0x44, 0x00, 0x44, 0x00, 
0x44, 0x00, 0x44, 0x00, 0x7E, 0x00, 0x41, 0x00, 
0xA5, 0xFC, 0xB1, 0x56, 0x80, 0x02, 0xFF, 0xFF,
0x1F, 0xF0, 0x3F, 0xF8, 0x3B, 0xF8, 0x3F, 0xB8, 
0x30, 0xF8, 0x1F, 0x08, 0x5F, 0xFC, 0x1F, 0xDC, 
0x1B, 0xFC, 0x9F, 0x0C, 0x18, 0xFC, 0x3F, 0xF8, 
0x2F, 0xE9, 0x3F, 0xF8, 0x20, 0x08, 0x7F, 0xFC,
0x06, 0x70, 0x09, 0x88, 0x08, 0x08, 0x08, 0x08, 
0x0F, 0xF8, 0x3F, 0xFE, 0x20, 0x02, 0x1F, 0xFC, 
0x10, 0x04, 0x14, 0x24, 0x23, 0x84, 0x21, 0x02, 
0x23, 0x82, 0x10, 0x04, 0x1F, 0xFC, 0x3F, 0xFE,
0x01, 0xF0, 0x02, 0x08, 0x1C, 0x84, 0x24, 0x14, 
0x44, 0x04, 0x42, 0x08, 0x31, 0xF0, 0x0C, 0x00, 
0x03, 0xC0, 0x00, 0x20, 0x08, 0x28, 0x0F, 0xF8, 
0x08, 0x48, 0x08, 0x48, 0x0F, 0xF8, 0x08, 0x08,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFC, 
0x41, 0xFE, 0xB8, 0xE3, 0x80, 0xFF, 0x90, 0xF7, 
0x90, 0xF7, 0x80, 0xFF, 0x41, 0xFF, 0x3F, 0xFE,
0x1F, 0x80, 0x20, 0x40, 0x1F, 0x80, 0x00, 0x00, 
0x0F, 0x00, 0x10, 0x80, 0x20, 0x40, 0x71, 0xE0, 
0x20, 0x40, 0x24, 0x40, 0x2A, 0x40, 0x20, 0x20, 
0x20, 0x1E, 0x20, 0x04, 0x10, 0x18, 0x0F, 0xE0,
0x1F, 0xC0, 0x20, 0x38, 0x40, 0x04, 0x48, 0x02, 
0x80, 0x02, 0x8F, 0x12, 0x83, 0x02, 0x60, 0x04, 
0x18, 0x18, 0x07, 0xE0, 0x04, 0x10, 0x08, 0x10, 
0x08, 0x08, 0x10, 0x08, 0x10, 0x08, 0x7C, 0x3E,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x14, 
0x28, 0x17, 0xE8, 0x11, 0x88, 0x0E, 0x70, 0x10, 
0x11, 0x50, 0x11, 0x48, 0x0F, 0xF8, 0x11, 0x44, 
0x20, 0x02, 0x20, 0x02, 0x1F, 0xFC, 0x0A, 0xA8,
0x1A, 0x58, 0x3F, 0xFC, 0x2F, 0xF4, 0x0B, 0xD0, 
0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x07, 0xE0, 
0x0F, 0xF0, 0x3F, 0xFC, 0x7F, 0xFE, 0xDB, 0xDB, 
0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFE, 0x3F, 0xFC,
0x01, 0x98, 0x02, 0x64, 0x05, 0x9A, 0x05, 0x0A, 
0x05, 0xFA, 0x48, 0x01, 0xA9, 0x05, 0xA9, 0x75, 
0xA8, 0x21, 0xA8, 0x21, 0xB4, 0x22, 0x43, 0xFC, 
0x40, 0x12, 0x4C, 0x89, 0x42, 0xC9, 0x3F, 0xFF,
0x00, 0x00, 0x01, 0x80, 0x0F, 0xF0, 0x1F, 0xF8, 
0x3F, 0xFC, 0x7F, 0xFE, 0xC3, 0x0F, 0xFF, 0xFF, 
0x7F, 0xFF, 0x7F, 0xFD, 0x55, 0x55, 0x55, 0x55, 
0xD5, 0x55, 0x15, 0x74, 0x72, 0xA6, 0x02, 0xA0,
0x07, 0xC0, 0x08, 0x20, 0x30, 0x18, 0x48, 0x24, 
0x48, 0x24, 0x20, 0x08, 0x23, 0x88, 0x23, 0x88, 
0x33, 0x98, 0x48, 0x24, 0x4F, 0xE4, 0x30, 0x18, 
0x08, 0x10, 0x08, 0x10, 0x09, 0x90, 0x06, 0x60,
0x00, 0x00, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x40, 
0x01, 0x80, 0x03, 0xE0, 0x00, 0x40, 0x00, 0x80, 
0x00, 0x00, 0x7F, 0xFC, 0xE0, 0x07, 0xC0, 0x25, 
0xDC, 0x75, 0xC0, 0x25, 0xE0, 0x07, 0x7F, 0xFC};


// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>

const uint8_t PROGMEM ntamago[] = //16x16
{0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x04, 0x20, 
0x0A, 0x50, 0x0A, 0x90, 0x1C, 0x88, 0x10, 0x78, 
0x10, 0x08, 0x26, 0x04, 0x29, 0x0C, 0x28, 0x94, 
0x28, 0x54, 0x34, 0x54, 0x1F, 0xF8, 0x0F, 0xF0};

const uint8_t PROGMEM tamabg[] = //128x64
{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6D, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB6, 
0x80, 0x00, 0x1C, 0x00, 0x00, 0x03, 0x61, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x86, 
0xBB, 0xDE, 0xED, 0xFF, 0xFF, 0xFB, 0x0F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 
0xA2, 0x52, 0xB4, 0x00, 0x00, 0x03, 0x5F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 
0xA2, 0x52, 0x94, 0x00, 0x00, 0x03, 0x5F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 
0xBA, 0x52, 0x94, 0x00, 0x00, 0x03, 0x1F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 
0xA2, 0x52, 0xB4, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xAB, 0xDE, 0xEC, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0x88, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0x84, 0x02, 0x0C, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xB9, 0xDC, 0xED, 0xFF, 0xFF, 0xFB, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xAC, 0x92, 0x4C, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xA4, 0x92, 0x5C, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xA4, 0x9D, 0x5C, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xAC, 0x92, 0x5C, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xB9, 0xD2, 0x5C, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0x84, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0x80, 0x00, 0xFC, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xBA, 0x52, 0xFD, 0xFF, 0xFF, 0xFB, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xA2, 0x5A, 0xFC, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xA2, 0x5A, 0xFC, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xBA, 0x56, 0xFC, 0x00, 0x00, 0x03, 0x7F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 
0xA2, 0x52, 0xFC, 0x00, 0x00, 0x03, 0x1F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 
0xAB, 0xD2, 0xFC, 0x00, 0x00, 0x03, 0x5F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 
0x88, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x5F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x61, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x86, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6D, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB6, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//  Tamagero Names
const String tamanames[] PROGMEM = { //Length 10 strings
"Shokero   ", //No.0
"Kikimono  ",
"Shirogato ",
"Kurogato  ",
"Lilparca  ",

"Niubi     ",
"Pumpmo    ",
"Bongos    ",
"Tedibea   ",
"Nillin    ",

"Guff      ",//No.10
"Same-Same ",
"Bween     ",
"Stackmo   ",
"Boshimole ",

"Kenda     ",
"Buroku    ",
"Azrael    ",
"D.O.N.G.  ",
"Mme Pinchy",

"Arbusto   ",//No.20
"Orion     ",
"Ikumi     ",
"Osuo      ",
"Yrettab   ",
"Same-Same " };



// = = = = = = = = = = Variables = = = = = = = = = = = = =
// Program Control
int MenuSt = 0;   //Menu State Variable
int MenuSel = 0;  //Menu Selector Variable
int MenuWind = 0; //Menu window no.
int MenuNextSt = 0;//Menu state to be transitioned to after half an A-press.

// Timing variables
int Twait = 300; //Time to wait after pressing a button.
int eggagemax = 100; //Max egg age before hatching
int aniTimer = 60;
int aniSt = 0;
int aniDir = 1;
int aniX = 0;

// Player variables
int xp = 0;
int txp = 0;
int xpcntr = 0;
int money = 0;
bool dex[25];

// Tamagero state
float hungry = 0;
float bored  = 0;
float dirty  = 0;
int level  = 0;
bool alive = true;
bool egg   = false; // make sure this is true before running
int age = 0;
int tamaid = 1;

// Other game variables
float hmax = 6000.0; //Max hunger level before running away
float dmax = 7500.0; //Max dirty level befroe running away
float bmax = 5000.0; //Max dirty level befroe running away
bool enLED = false; //Enable LED indicator for Tamagero health
int L = 10;
const int8_t sprite[32] PROGMEM = {
0x1C, 0x38, 0x30, 0x0C, 0x38, 0x1C, 0x1E, 0x78, 
0x3F, 0xFC, 0x7C, 0x3E, 0xC8, 0x13, 0x89, 0x91, 
0x89, 0x91, 0xC8, 0x93, 0xFC, 0xBF, 0xBF, 0xFD, 
0x9B, 0xEC, 0x95, 0xA4, 0x04, 0x80, 0x00, 0x80}; 

// -  - - - - - - - - -  - - - - - - - - - - - - - - - - - - - -

int dialogue(String string) {
  ab.setCursor(0,0);
  ab.print("\n");
  ab.print(string);
  //some other stuff to make this look nice
  ab.display();

  ab.pollButtons();
  while (!ab.pressed(A_BUTTON)) {
    ab.pollButtons();
  }

  return 0;
}

void setID(int id) {
  // Wrapper that aligns seen Tamagero with the Tamadex listing
  tamaid = id;
  dex[id] = true;
}



// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>
//                    Setup Program Code
// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>
void setup() {
  // put your setup code here, to run once:
  ab.begin(); //Arduboy splash
  ab.setFrameRate(30);
  ab.initRandomSeed();
  ab.clear();


  // My splash
  ab.setTextColor(WHITE);
  ab.print("Tamagero Ver. 0.2\nKurt Butler");
  ab.display();

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  
  // ============= Game Init! ==================
  // Initialize Tamadex
  for (int i=0; i<25; i++) {dex[i] = false;}
  setID(0);//rand()%25;
  

  delay(1000);
  ab.clear();
  ab.display();

  //GameSt=0;
}


// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>
//                    Main Program Code
// <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>
void loop() {
  // put your main code here, to run repeatedly:

  //wait and look at buttons
  if (!ab.nextFrame())
    return;
  ab.pollButtons();

  // = = = Update internal variables = = =
  // Menu Update
  if (MenuSt != MenuNextSt) { MenuSel = 0; delay(Twait); }
  MenuSt = MenuNextSt;

  // Tamagero update
  if (alive) {
    if (egg) {
      // Egg Life
      if (age < eggagemax) { age++; }
      else { egg = false; age = 0;  }
    } else {
      //Tamagero life update
      age++; 
      if (hungry < hmax) {hungry++;}
      if (dirty  < dmax) {dirty++;}
      if (bored  < bmax) {bored++;}

      //Check if the Tamagero is dead
      if (hungry >= hmax-1 || dirty >= dmax-1) {
        // DEATH
        alive = false;
        hungry = 0; bored = 0; dirty = 0; xp = 0;
        //        #####################
        dialogue("Your tamagero has run\naway!");
      } else {
        // EXP System
        if (xpcntr <= 0) {
          xp++; txp++; xpcntr = 300; 
          if (bored <= 0.1*bmax) {money++;}
          if (xp > level*10 + 0.1*xp) {level++; money = money+10+level;}
        } else {
          xpcntr--;
        }
      }
      
    }
  }

  // = = = Update status LED = = =
  if (!alive || !enLED) { //LED Off
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
  }
  else if (egg) { //LED Blue
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
  }
  else {
    if (hungry > 0.9 * hmax || dirty > 0.9 * hmax) {//LED Blue
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(BLUE_LED, HIGH);
    } //LED red
    else if (hungry > 0.5 * hmax || dirty > 0.5 * hmax) {//LED Blue
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
    } //LED yellow
    else {//LED Blue
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
    }//LED green
  }

  //ApplyProgmemMenuAction(player, EquipmentMenu, menuIndex);

  // = = = = = Menu Control Logic = = = = =
  // Main Menu
  MenuNextSt = MenuSt;
  if (MenuSt == 0) {
    if (ab.pressed(A_BUTTON)) {
      if (MenuSel==0) {MenuNextSt = 2;}
      if (MenuSel==1) {MenuNextSt = 1;} 
      if (MenuSel==2) {enLED = !enLED; delay(Twait);} 
      }
    else if (ab.pressed(B_BUTTON)) { age = age; }
    else if (ab.pressed(UP_BUTTON) && MenuSel > 0) { MenuSel--; delay(Twait);}
    else if (ab.pressed(DOWN_BUTTON) && MenuSel < 2) { MenuSel++; delay(Twait);}
  }

  // Action Menu
  if (MenuSt == 2) {
    if (ab.pressed(A_BUTTON)) {
      if (MenuSel==0) { // FEED TAMAGERO
        //                            #####################
        if (bored == bmax) {dialogue("Your tamagero refused\nto eat!");} // Only if not starving 
        else {hungry = 0;} //Maybe make this incremental ?
      }
      if (MenuSel==1) { // CLEAN TAMAGERO
        if (bored == bmax) {dialogue("Your tamagero refused\nto bathe!");}
        else {dirty = 0;}
      }
      if (MenuSel==2) {bored = 0;}
      if (MenuSel==3) {age = 0; egg = true; alive = true;}
    }
    else if (ab.pressed(B_BUTTON)) { MenuNextSt = 0; delay(Twait); }
    else if (ab.pressed(UP_BUTTON) && MenuSel > 0) { MenuSel = MenuSel - 1; delay(Twait); }
    else if (ab.pressed(DOWN_BUTTON) && MenuSel < 3) {  MenuSel = MenuSel + 1; delay(Twait); }
  }
  
  // Stats Menu
  if (MenuSt == 1) {
    if (ab.pressed(B_BUTTON)) { MenuNextSt = 0; delay(Twait); }
    else if (ab.pressed(A_BUTTON)) { 
      if (MenuSel==0) { MenuNextSt = 3;}
      if (MenuSel==1) { MenuNextSt = 4;}
      delay(Twait); 
    }
    else if (ab.pressed(UP_BUTTON) && MenuSel > 0) { MenuSel = MenuSel - 1; delay(Twait); }
    else if (ab.pressed(DOWN_BUTTON) && MenuSel < 1) {  MenuSel = MenuSel + 1; delay(Twait); }
  }
  
  // Info Menus
  if (MenuSt == 3 || MenuSt == 4) {
    if (ab.pressed(B_BUTTON)) { MenuNextSt = 1; delay(Twait); }
    else if (ab.pressed(A_BUTTON)) {  MenuNextSt = 0; delay(Twait); }
  }





  // <> <> <> <> <> <> <> <> <>  Update graphics <> <> <> <> <> <> <> <> <> 
  ab.clear();
  //ab.drawSlowXYBitmap(50, 10, (tama0), 16, 16, WHITE);
  ab.drawSlowXYBitmap(0, 0, (tamabg), 128,64, WHITE);
  L =22-(22*hungry)/hmax;
  ab.fillRect(23,5,  L,  3,WHITE); //FOOD   (max pix is 22)    // LATER: Make sure these use saturated arithmetic
  L = (22*dirty)/dmax;
  ab.fillRect(23,14, L,  3,WHITE);//DIRT
  L = 22-(22*bored)/bmax;
  ab.fillRect(23,23, L,  3,WHITE);//FUN

  // Draw tamagero sprite
  if (aniTimer<=0) {
    if (aniSt==0) {aniSt=1; aniTimer=1; aniX++;}
    else if (aniSt==1) {aniSt=2; aniTimer=1; aniX++;}
    else if (aniSt==2) {aniSt=3; aniTimer=1; }
    else if (aniSt==3) {aniSt=4; aniTimer=30 +  (rand() % 30);}
    else if (aniSt==4) {aniSt=5; aniTimer=1;  aniX--;}
    else if (aniSt==5) {aniSt=0; aniTimer=40 +  (rand() % 30);  aniX--; aniDir = 2*(rand()%2)-1;}
  } else {aniTimer--;}
  if (alive) {
    if (egg) {
      ab.drawSlowXYBitmap(75, 15, ntamago, 16, 16, BLACK);
    } else {
      ab.drawSlowXYBitmap(75+aniDir*aniX, 15-(aniSt%2), (ntamablock + 32*tamaid), 16, 16, BLACK);
    }
  }

  
  // <> <> <> <> <> <> <> <> <> Menu Text <> <> <> <> <> <> <> <> <> <> 
  ab.setCursor(0,32);
  //ab.print("  Actions\n* Statistics\n  Sleep\n  Settings");
  if (MenuSt == 0) {// Main Menu
    if (MenuSel==0) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Actions\n");
    if (MenuSel==1) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Statistics\n");
    if (MenuSel==2) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Toggle LED\n");
//    if (MenuSel==3) {ab.print("*");} else {ab.print(" ");}
ab.print(aniTimer);
ab.print("|");
ab.print(aniSt);
//    ab.print(" Settings");
  }
  if (MenuSt == 2) {// Action Menu
    if (MenuSel==0) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Feed\n");
    if (MenuSel==1) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Clean\n");
    if (MenuSel==2) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Play\n");
    if (MenuSel==3) {ab.print("*");} else {ab.print(" ");}
    ab.print(" RESET!");
  }
  if (MenuSt == 1) { // Stats Menu
    if (MenuSel==0) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Tama Stats\n");
    if (MenuSel==1) {ab.print("*");} else {ab.print(" ");}
    ab.print(" Player Stats\n");
  }
  if (MenuSt==3) {  // Tamagero Info
    if (tamaid!=11) { ab.print(tamanames[(tamaid % 25)]); }
    else {ab.print(tamanames[25]);}
    ab.print(" \nAge:");
    ab.print((((age)/30.0)/3600.0),3);
    ab.print(" hr\nXp: ");
    ab.print(xp);
    ab.print("  \nLvl:");
    ab.print(level);
  }
  if (MenuSt==4) {  //   Player Info
    //        #####################
    ab.print(  "Total Xp: ");
    ab.print(txp);
    ab.print("\nMoney:    ");
    ab.print(money);
    
    //Tamadex display
    ab.print("\nDex ");
    for (int i=0; i<25; i++) {
      if (dex[i]) {ab.print("o");}
      else {ab.print("-");}
      if (i==12) {ab.print("\n    ");}
      //if ((i%4==3)&(i<16)) {ab.print("  ");}
      //if ((i%4==0)&(i>16)) {ab.print("  ");}
    }
  }
  
  //ab.print("  (");
  //ab.print(MenuSt);
  //ab.print(",");
  //ab.print(MenuSel);
  //ab.print(") &");
  //ab.print(tamaid);
  //ab.print(L);
  ab.display();

  if (ab.pressed(RIGHT_BUTTON)) {setID((tamaid+1)%25); delay(Twait);}
  if (ab.pressed(LEFT_BUTTON))  {setID((tamaid+24)%25); delay(Twait);}
  
}

