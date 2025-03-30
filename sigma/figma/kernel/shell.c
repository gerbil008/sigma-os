#include "../include/shell.h"

char key;

size_t shell_routine(){
    key = get_key();
    if(key != 0){
        putchar(key);
    }
    return 0;
}