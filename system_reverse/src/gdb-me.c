#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    char buf[0x60];
    int res;

    printf("Hello world!");
    scanf("%s", buf);

    for (int i=0; i<5; i++) {
        printf("Loop : %d\n", i);
    }

    res = add(100, 70);
    printf("Result : %d\n", res);

    return 0;
}