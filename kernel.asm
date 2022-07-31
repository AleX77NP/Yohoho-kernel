;;kernel.asm
bits 32         ;;nasm directive
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002			;magic
        dd 0x00				;flags
        dd - (0x1BADB002 + 0x00)	;checksum. m+f+c should be zero

global start
extern kernel_main    ;kmain is defined in the c program

start:
        cli     ;block interrupts
        call kernel_main
        hlt     ;halt the CPU