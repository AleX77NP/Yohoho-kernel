SLittle kernel in C & Assembly
==============================

Little kernel loadable with the GRUB bootloader on x86 system.

Tools you need installed:
- x86 machine
- Linux
- NASM assembler
- ld (linker by GNU)
- grub
- qemu emulator

Copy code and then run these commands in the order:

Create object file for assembly code:
1. ```nasm -f elf32 kernel.asm -o kasm.o```

Create object file for c code:
2. ```gcc -m32 -c kernel.c -o kc.o```

Link and create executable:
3. ```ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o```

Run it with qemu:
4. ```qemu-system-i386 -kernel kernel```


And yes, "yohohohoho!" in the C code is actually the One Piece reference! Brook ;)

