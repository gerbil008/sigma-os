#ifndef SHELL
#define SHELL
#include "tty.h"
#include "../libc/libc.h"
#include "../hardware/keyboard/key_input.h"
#include "PIT.h"

size_t shell_routine();
void shell_init();

#endif