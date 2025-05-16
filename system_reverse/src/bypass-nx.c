// ASLR : ON
// gcc bypass-nx.c -o bypass-nx -fno-stack-protector -no-pie

#include <stdio.h>
#include <stdint.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void win() {
    write(1, "try to call me\n", 15);
    system("/bin/sh");
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