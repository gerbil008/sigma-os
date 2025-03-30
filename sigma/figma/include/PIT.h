#ifndef PIT
#define PIT
#define PIT_CMD  0x43
#define PIT_CH0  0x40
#define PIT_FREQ 1193182

#include <stdint.h>
#include "../hardware/I-O.h"

void pit_set_frequency(uint32_t freq);
void pit_poll(uint32_t*pit_ticks);

#endif
