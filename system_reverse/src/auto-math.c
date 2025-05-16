#include <stdio.h>
#include <stdint.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    srand(time(NULL));
}

int main() {
    uint32_t user_answer, answer;
    uint32_t var1, var2;

    setup();

    for (int i=0; i<1000; i++) {
        var1 = rand() % 0xffff;
        var2 = rand() % 0xffff;

        if (rand() % 2) {
            answer = var1 + var2;
            printf("Q#%d) %u + %u = ", i, var1, var2);
        } else {
            answer = var1 * var2;
            printf("Q#%d) %u * %u = ", i, var1, var2);
        }

        scanf("%u", &user_answer);
        if (answer == user_answer) {
            puts("Correct!");
        } else {
            puts("Wrong...");
            exit(0);
        }
    }
    
    puts("You are now friendly with Pwntools :)");
    return 0;
}