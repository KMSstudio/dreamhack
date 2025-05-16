#include <stdio.h>

void stage1() {
	int num1, num2;

	puts("--------- Stage 1 ---------");
	printf("Input : ");
	scanf("%d %d", &num1, &num2);

	if (num1 + num2 != 1337)
		explode();
}

void stage2() {
    char buf[8];

	puts("--------- Stage 2 ---------");
	printf("Input : ");
	scanf("%7s", buf);

	if (buf[0] == 'P'
		&& buf[1] == 'a'
		&& buf[2] == 's'
		&& buf[3] == 's'
		&& buf[4] == '_'
		&& buf[5] == 'M'
		&& buf[6] == 'e') return;
	
	explode();
}

int stage3_s(int num) {
	if (num == 1) return num;
	return num * stage3_s(num - 1);
}

void stage3() {
	int num;
	puts("--------- Stage 3 ---------");
	
	printf("Input : ");
	scanf("%d", &num);

	if (stage3_s(num) != 120) explode();
}

void stage4() {
    int num[5];

	puts("--------- Stage 4 ---------");
	printf("Input : ");
	scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

	if (num[0] != 3) explode();
	if (num[1] != 4) explode();

	for (int i=0; i<3; i++) {
		if ((num[i] + num[i+1]) != num[i+2]) explode();
	}
}

struct node {
	int val;
	struct node *next;
};

struct node node7 = { .val = 844, .next = NULL};
struct node node6 = { .val = 385, .next = &node7};
struct node node5 = { .val = 123, .next = &node6};
struct node node4 = { .val = 456, .next = &node5};
struct node node3 = { .val = 964, .next = &node4};
struct node node2 = { .val = 479, .next = &node3};
struct node node1 = { .val = 885, .next = &node2};

void stage5() {
    int start, len;

	puts("--------- Stage 5 ---------");
	printf("Input : ");	
	scanf("%d %d", &start, &len);

	struct node *cur = &node1;
	int sum = 0;

	for (int i=0; i<start; i++) {
		cur = cur->next;
	}
	for (int i=0; i<len; i++) {
		sum += cur->val;
		cur = cur->next;
	}

	if (sum != (456 + 123 + 385)) explode();
	
}

void explode() {
    puts("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    puts("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    puts("XXXXXXXXXXXX BOMB HAS BEEN EXPLODED XXXXXXXXXXXX");
    puts("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    puts("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    exit(0);
}

void defused() {
    puts("\n\n!!!!!!!!!! YOU HAVE DEFUSED THE BOMB !!!!!!!!!!\n\n");
	puts("             . . .                         ");
	puts("              \\|/                          ");
	puts("            `--+--'                        ");
	puts("              /|\\                          ");
	puts("             ' | '                         ");
	puts("               |                           ");
	puts("               |                           ");
	puts("           ,--'#`--.                       ");
	puts("           |#######|                       ");
	puts("        _.-'#######`-._                    ");
	puts("     ,-'###############`-.                 ");
	puts("   ,'#####################`,               ");
	puts("  /#########################\\              ");
	puts(" |###########################|             ");
	puts("|#############################|            ");
	puts("|#############################|            ");
	puts("|#############################|            ");
	puts("|#############################|            ");
	puts(" |###########################|             ");
	puts("  \\#########################/              ");
	puts("   `.#####################,'               ");
	puts("     `._###############_,'                 ");
	puts("        `--..#####..--'");
}

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
	setup();
    stage1();
    stage2();
    stage3();
    stage4();
    stage5();

    defused();
}