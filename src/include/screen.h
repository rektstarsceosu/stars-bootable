#include <stdint.h>

typedef struct {
    char c;
    uint8_t color;
}__attribute__((packed)) vidmem_t ;

typedef struct{
    uint8_t x;
    uint8_t y;
} cursor_t;

enum {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

static const uint8_t MAX_X = 79;
static const uint8_t MAX_Y = 24;

static vidmem_t* vidmem = (vidmem_t*) 0xb8000;
static cursor_t cursor;

void putc(vidmem_t c);
uint32_t puts(char* s,uint8_t fg,uint8_t bg);
vidmem_t mkchar(char c,uint8_t fg,uint8_t bg);
void scroll(void);
