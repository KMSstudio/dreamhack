// ASLR : ON
// gcc bypass-pie.c -o bypass-pie -fno-stack-protector

#include <stdio.h>
#include <stdint.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln() {
    uint64_t arr[4] = {0x1111, 0x2222, 0x3333, 0x4444};
    size_t idx;
    char choice[0x10];

    while (1) {
        printf("[R]ead / [W]rite / [E]xit : ");
        memset(choice, 0, 0x10);
        read(0, choice, 0x10);

        if (choice[0] == 'R') {
            printf("Index : ");
            scanf("%zu", &idx);
            printf("Data : %lld\n", arr[idx]);
        } else if (choice[0] == 'W') {
            printf("Index : ");
            scanf("%zu", &idx);
            printf("Data : ");
            scanf("%zu", &arr[idx]);                  
        } else if (choice[0] == 'E') {
            break;
        } else {
            puts("Invalid choice\n");
        }
    }

    return;
}

int main() {
    setup();
    vuln();
}