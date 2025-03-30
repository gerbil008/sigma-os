//I FUCKING HATE CPU_CYLE_TIMING
#include "../include/shell.h"

char keyin = 0;
char prev_key = 0;
//uint32_t pit_ticks = 0;
//uint32_t pit_ticks_bef = 0;

uint16_t _cycle_time = 0;//_shell_cycles/_shell_cycles_divider
uint16_t _cycle_times = 0;

void shell_init() {
    printf("\n/sorry_no_filesystem_yet@standard: ");
    //pit_set_frequency(5);
    //pit_poll(&pit_ticks);
}

/*size_t shell_routine() {
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
FUCK PIT*/

/*size_t shell_routine() {
    _cycle_time++;
    if(_cycle_time >= _shell_cycles/_shell_cycles_divider){
        _cycle_time = 0;
        _cycle_times++;

    }
    keyin = get_key();
    if (keyin != 0) {
        if (_cycle_times >= _shell_cycles_divider) {
            _cycle_time = 0;
            _cycle_times = 0;
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
}ALSO FUCK CPU_CYCLES. AND MIKROWEICH*/

size_t shell_routine() {
    keyin = get_key();
    if (keyin != 0) {
        if (keyin != prev_key) {
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