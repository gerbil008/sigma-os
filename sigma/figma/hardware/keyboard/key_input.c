#include "key_input.h"



char get_keypress() {
    return inb(KEYBOARD_DATA_PORT);
}

char scancode_to_ascii(uint8_t code) {
    static char keymap_us[128] = {0,    27,  '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-', '=',  '\b',
                                  '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',  '[', ']', '\n', 0,
                                  'a',  's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,   '\\', 'z',
                                  'x',  'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,   '*',  0,   ' ', 0};

    return (code < 128) ? keymap_us[code] : 0;
}

char get_key_blocking() {
    char key = 0;
    while (1) {
        key = get_keypress();
        key = scancode_to_ascii(key);
        if (key) {
            return key;
        }
    }
}

char get_key(void) {
    return scancode_to_ascii(get_keypress());
}
