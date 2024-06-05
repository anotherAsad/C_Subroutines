#include <stdio.h>

// Cred begin: Adam Rosenfield
#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
// Cred end: Adam Rosenfield
#define sub_exec(subroutine_name) {stack[stack_ptr++] = &&TOKENPASTE2(subroutine_name, __LINE__); goto subroutine_name; TOKENPASTE2(subroutine_name, __LINE__):}
#define sub_exit {goto *stack[--stack_ptr];}

int lim = 10;

static void *stack[100];
static int stack_ptr = 0;

void test() {
	int k = 4;

	for(int i = 0; i<lim; i++) {
		sub_exec(subroutine_0);
		printf("And back!\n");

		sub_exec(subroutine_1);
		printf("And back!\n");
	}

    return;

    subroutine_0:
        printf("Here: %d\n", k++);
        sub_exit;

	subroutine_1:
        printf("THere: %d\n", __LINE__);
        sub_exit;
}

int main(int argc, char **argv) {
	//g = *argv[0];

	test();
	printf("\n");
}
