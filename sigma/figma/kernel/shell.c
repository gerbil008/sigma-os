#include "../include/shell.h"

char keyin = 0;
char prev_key = 0;
uint32_t pit_ticks = 0;
uint32_t pit_ticks_bef = 0;

void shell_init() {
    printf("\n/sorry_no_filesystem_yet@standard: ");
    pit_set_frequency(5);
    pit_poll(&pit_ticks);
}

size_t shell_routine() {
    pit_poll(&pit_ticks);
    keyin = get_key();
    if (keyin != 0) {
        if (pit_ticks > pit_ticks_bef) {
            pit_ticks_bef = pit_ticks;
            switch (keyin) {
            case '\b': {
                change_column(get_column() - 1);
                putchar(' ');
                change_column(get_column() - 1);
                break;
            }
            default: {
                putchar(keyin);
            }
            }
        }
        prev_key = keyin;
        keyin = 0;
    }
    return 0;
}