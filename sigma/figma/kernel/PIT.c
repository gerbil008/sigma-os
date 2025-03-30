#include "../include/PIT.h"

void pit_set_frequency(uint32_t freq) {
    uint16_t divisor = (uint16_t)(PIT_FREQ / freq);
    outb(PIT_CMD, 0x36);
    outb(PIT_CH0, divisor & 0xFF); 
    outb(PIT_CH0, divisor >> 8);   
}

void pit_poll(uint32_t * pit_ticks) {
    static uint32_t last_pit_value = 0;
    uint32_t current_pit_value;

    current_pit_value = inb(PIT_CH0);  
    current_pit_value |= (inb(PIT_CH0) << 8);  

    if (current_pit_value < last_pit_value) {
        (*pit_ticks)++;  
    }

    last_pit_value = current_pit_value;  
}

