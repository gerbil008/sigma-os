#include "../libc/libc.h"
#include "../include/tty.h"
#include "../include/shell.h"

void kernel_main(void) {
	terminal_initialize();
	printf("Welcome to Figma-OS!\n");
	shell_init();
	while(1){
		if(shell_routine() == 1){
			abort();
		}
	}
}