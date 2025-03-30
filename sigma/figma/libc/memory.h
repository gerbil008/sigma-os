#ifndef MEMORY_H
#define MEMORY_H
#include "string.h"

int memcmp(const void* aptr, const void* bptr, size_t size);

void* memmove(void* dstptr, const void* srcptr, size_t size);

void* memset(void* bufptr, int value, size_t size);

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size);

#endif
