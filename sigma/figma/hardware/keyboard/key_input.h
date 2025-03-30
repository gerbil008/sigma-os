#ifndef KEYBOARD_INPUT
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define KEYBOARD_INPUT
#define KEYBOARD_DATA_PORT 0x60

static char keymap_us[128] = {0,    27,  '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-', '=',  '\b',
                              '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',  '[', ']', '\n', 0,
                              'a',  's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,   '\\', 'z',
                              'x',  'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,   '*',  0,   ' ', 0};

static char keymap_de[128] = {
    0,    27,  '1', '2',  '3', '4', '5', '6', '7',  '8', '9', '0', '-', '=', '\b', '\t', 'q', 'w', 'e', 'r',
    't',  'z', 'u', 'i',  'o', 'p', '[', ']', '\n', 0,   'a', 's', 'd', 'f', 'g',  'h',  'j', 'k', 'l', ';',
    '\'', 'ä', 0,   '\\', 'y', 'x', 'c', 'v', 'b',  'n', 'm', ',', '.', '/', 0,    '*',  0,   ' ', 0,
};

char get_keypress(void);
char scancode_to_ascii(uint8_t code);
char get_key_blocking();
char get_key(void);

#endif