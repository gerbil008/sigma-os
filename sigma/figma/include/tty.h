#ifndef FIGMA_TTY_H
#define FIGMA_TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void change_column(size_t num);
size_t get_column(void);

#endif