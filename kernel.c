// kernel.c - version 1

#define WHITE_TEXT 0x07 // light gray on black text

void kernel_clear_screen();
unsigned int kernel_printf(char *msg, unsigned int line);

void kernel_main() {

    kernel_clear_screen();
    kernel_printf("Hi from little kernel, yohohohoho!", 0);
}

// clear entire screen
void kernel_clear_screen() {
    char *vidmem = (char *) 0xb8000;
    unsigned int i=0;

    while(i < (80*25*2)) {
        vidmem[i] = ' ';
        i++;
        vidmem[i] = WHITE_TEXT;
        i++;
    }
}

// message and line
unsigned kernel_printf(char *msg, unsigned int line) {
    char *vidmem = (char *) 0xb8000;
    unsigned int i=0;

    i = (line*80*2);

    while(*msg != 0) {
        if(*msg=='\n') {
            line++;
            i = (line*80*2);
            *msg++;
        } else {
            vidmem[i] = *msg;
            *msg++;
            i++;
            vidmem[i] = WHITE_TEXT;
            i++;
        }
    }

    return(1);

}