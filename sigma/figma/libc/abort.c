#include "stdio.h"
#include "stdlib.h"
#include "libc.h"

__attribute__((__noreturn__))
void abort(void) {
	printf("We ran into an error and have to halt. Please consider switching to Arch Linux\n");
    asm volatile("hlt");}
