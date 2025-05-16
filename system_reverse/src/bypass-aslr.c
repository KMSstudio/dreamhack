// ASLR : ON
// gcc bypass-aslr.c -o bypass-aslr -fno-stack-protector -no-pie -z execstack

#include <stdio.h>
#include <stdint.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void leak() {
    uint64_t arr[0x20];

    for (int i=0; i<0x20; i++)
       printf("0x%llx\n", arr[i]); // print uninitialized stack

    return;
}

void vuln() {
    char buf[0x40];

    printf("Input : ");
    read(0, buf, 0x200);

    return;
}

int main() {
    setup();
    leak();
    vuln();
}