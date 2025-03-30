#include "key_input.h"

static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

char get_keypress() {
    return inb(KEYBOARD_DATA_PORT);
}

char scancode_to_ascii(uint8_t code) {
    static char keymap[128] = {0,    27,  '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-', '=',  '\b',
                               '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',  '[', ']', '\n', 0,
                               'a',  's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,   '\\', 'z',
                               'x',  'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,   '*',  0,   ' ', 0};

    return (code < 128) ? keymap[code] : 0;
}

char get_key_blocking(){
    char key = 0;
    while(1){
        key = get_keypress();
        key = scancode_to_ascii(key);
        if(key){
            return key;
        }
    }
}
