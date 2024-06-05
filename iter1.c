#include <stdio.h>

// -- Does not support array of subroutines generated at compile time

// Cred begin: Adam Rosenfield
#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
// Cred end: Adam Rosenfield
#define sub_exec(subroutine_name) {subroutine_name = &&TOKENPASTE2(subroutine_name, __LINE__); goto subroutine_name; TOKENPASTE2(subroutine_name, __LINE__):}
#define sub_exit(subroutine_name) {goto *subroutine_name;}

void test() {
	void *subroutine_0, *subroutine_1;

	int k = 4;

	sub_exec(subroutine_0);

    printf("And back!\n");

	sub_exec(subroutine_1);

	printf("And back!\n");

    return;

    subroutine_0:
        printf("Here: %d\n", k++);
        sub_exit(subroutine_0);

	subroutine_1:
        printf("THere: %d\n", __LINE__);
        sub_exit(subroutine_1);
}

int main(int argc, char **argv) {
	//g = *argv[0];

	test();
	printf("\n");
}
