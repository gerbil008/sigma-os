#ifndef LIBC
#define LIBC
#include "memory.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

size_t strlen(const char* str);
__attribute__((__noreturn__)) void abort(void);

#endif