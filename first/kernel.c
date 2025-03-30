#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#endif

#if !defined(__i386__)
#endif

#define STR_MAX 32768

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t)uc | (uint16_t)color << 8;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

char written[STR_MAX];
uint32_t wr_decr = 0;

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*)0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void clear_terminal(void){
    terminal_row = 0;
    terminal_column = 0;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

char* sstrip_str(const char* msg, char del) {
    char* re = "";
    size_t len = strlen(msg);
    for (size_t i = 0; i < len; i++) {
        if (msg[i] == del) {
            i++;
            for (size_t a = i; a < (len - i); a++) {
                re += msg[a];
            }
            return re;
        }
    }
    return "";
}

void strip_str(const char* msg, char del, char* result) {
    size_t len = strlen(msg);
    size_t j = 0;
    bool found_del = false;

    for (size_t i = 0; i < len; i++) {
        if (msg[i] == del && !found_del) {
            found_del = true;
        } else if (found_del) {
            result[j++] = msg[i];
        }
    }
}

void terminal_setcolor(uint8_t color) {
    terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
    written[wr_decr] = c;
    wr_decr++;
}

void terminal_putchar(char c) {
    if (c == '\n') {
        terminal_row++;
        terminal_column = 0;
        written[wr_decr] = c;
        wr_decr++;
    } else {
        terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH) {
            terminal_column = 0;
        }
        if (terminal_row == VGA_HEIGHT) {
            clear_terminal();
            terminal_row = 0;
            terminal_column = 0;
            char figma[STR_MAX];
            strip_str(written, '\n', figma);
            for (size_t i = 0; i < strlen(figma); i++) {
                terminal_putchar(figma[i]);
            }
            terminal_column = 0;
        }
    }
}

void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void terminal_writestring(const char* data) {
    terminal_write(data, strlen(data));
}

void kernel_main(void) {
    terminal_initialize();
    terminal_writestring(
        "Dies ist der erste Satz.\nDies ist der zweite Satz.\nDies ist der dritte Satz.\nDies ist der vierte "
        "Satz.\nDies ist der fünfte Satz.\nDies ist der sechste Satz.\nDies ist der siebte Satz.\nDies ist der achte "
        "Satz.\nDies ist der neunte Satz.\nDies ist der zehnte Satz.\nDies ist der elfte Satz.\nDies ist der zwölfte "
        "Satz.\nDies ist der dreizehnte Satz.\nDies ist der vierzehnte Satz.\nDies ist der fünfzehnte Satz.\nDies ist "
        "der sechzehnte Satz.\nDies ist der siebzehnte Satz.\nDies ist der achtzehnte Satz.\nDies ist der "
        "neunzehnte\nsigma \nsigma \nsigma \nsigma \nsigma \n fich you \n fugma");
     //terminal_writestring("\nuggma");   
}