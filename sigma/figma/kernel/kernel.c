#include "../libc/stdio.h"

#include "../include/tty.h"

void kernel_main(void) {
	terminal_initialize();
	printf("Welcome to Figma-OS!\n");
}