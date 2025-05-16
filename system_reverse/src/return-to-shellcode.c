// ASLR : OFF
// gcc return-to-shellcode.c -o return-to-shellcode -fno-stack-protector -no-pie -z execstack

#include <stdio.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
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