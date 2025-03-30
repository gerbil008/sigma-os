#ifndef KEYBOARD_INPUT
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define KEYBOARD_INPUT
#define KEYBOARD_DATA_PORT 0x60

char get_keypress(void);
char scancode_to_ascii(uint8_t code);
char get_key_blocking();

#endif