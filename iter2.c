#include <stdio.h>

// Cred begin: Adam Rosenfield
#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
// Cred end: Adam Rosenfield
#define sub_exec(subroutine_name, return_addr) {return_addr = &&TOKENPASTE2(subroutine_name, __LINE__); goto subroutine_name; TOKENPASTE2(subroutine_name, __LINE__):}
#define sub_exit(subroutine_name) {goto *subroutine_name;}

int lim = 10;

void test() {
	static void *ret_addr;

	int k = 4;

	for(int i = 0; i<lim; i++) {
		sub_exec(subroutine_0, ret_addr);
		printf("And back!\n");

		sub_exec(subroutine_1, ret_addr);
		printf("And back!\n");
	}

    return;

    subroutine_0:
        printf("Here: %d\n", k++);
        sub_exit(ret_addr);

	subroutine_1:
        printf("THere: %d\n", __LINE__);
        sub_exit(ret_addr);
}

int main(int argc, char **argv) {
	//g = *argv[0];

	test();
	printf("\n");
}
