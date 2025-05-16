// ASLR : ON
// gcc bypass-relro.c -o bypass-relro -fno-stack-protector -no-pie -Wl,-z,relro -Wl,-z,now

#include <stdio.h>
#include <stdint.h>

void gadget() {
    asm("pop %rdi");
    asm("ret");
    asm("pop %rsi");
    asm("ret");
    asm("pop %rdx");
    asm("ret");
}

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln() {
    char buf[0x40];

    write(1, "Input : ", 8);
    read(0, buf, 0x200);

    return;
}

int main() {
    setup();
    vuln();
}