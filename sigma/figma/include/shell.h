#ifndef SHELL
#define SHELL
#include "tty.h"
#include "../libc/libc.h"
#include "../hardware/keyboard/key_input.h"
#include "PIT.h"

#define _shell_cycles 400000000
#define _shell_cycles_divider 10000

size_t shell_routine();
void shell_init();

#endif