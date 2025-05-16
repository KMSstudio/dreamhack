// ASLR : ON
// gcc return-to-libc.c -o return-to-libc -fno-stack-protector -no-pie

#include <stdio.h>
#include <stdint.h>

char help[] = "/bin/sh";

void gadget() {
    asm("pop %rdi");
    asm("ret");
}

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void not_win() {
    system("echo Hello");
}

void vuln() {
    char buf[0x40];

    printf("Input : ");
    read(0, buf, 0x200);

    return;
}

int main() {
    setup();
    vuln();
}