#include "stdio.h"
#include "../include/tty.h"

int putchar(int ic) {
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
}