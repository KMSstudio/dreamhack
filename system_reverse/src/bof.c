// gcc bof.c -o bof -fno-stack-protector -no-pie -z execstack

#include <stdio.h>

int main() {
    char buf[0x20];

    printf("input : ");
    scanf("%s", buf);

    return 0;
}