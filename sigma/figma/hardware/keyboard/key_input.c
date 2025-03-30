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

    return (code < 128) ? keymap_us[code] : 0;
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

char get_key(void){
    return scancode_to_ascii(get_keypress);
}
