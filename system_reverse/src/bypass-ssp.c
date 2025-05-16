// ASLR : ON
// gcc bypass-ssp.c -o bypass-ssp -no-pie

#include <stdio.h>
#include <stdint.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln() {
    char buf[0x40];

    while (1) {
        printf("Input : ");
        read(0, buf, 0x200);

        if (strncmp(buf, "return", 6) == 0) {
            break;
        }

        printf("Your input : %s\n", buf);
    }

    return;
}

int main() {
    setup();
    vuln();
}