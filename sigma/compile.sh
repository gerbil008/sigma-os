i686-elf-as figma/kernel/boot.S -o figma/obj/boot.o
i686-elf-as figma/kernel/crti.S -o figma/obj/crti.o
i686-elf-as figma/kernel/crtn.S -o figma/obj/crtn.o
i686-elf-gcc -c figma/kernel/kernel.c -o figma/obj/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/kernel/tty.c -o figma/obj/tty.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/abort.c -o figma/obj/abort.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/memcmp.c -o figma/obj/memcmp.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/memcpy.c -o figma/obj/memcpy.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/memmove.c -o figma/obj/memmove.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/memset.c -o figma/obj/memset.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/printf.c -o figma/obj/printf.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/strlen.c -o figma/obj/strlen.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c figma/libc/putchar.c -o figma/obj/putchar.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
