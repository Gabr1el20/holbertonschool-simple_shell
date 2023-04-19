#include "main.h"

void main(void)
{
	int a = 10, b = 5, sum = a + b;
	pid_t ppid = getppid();

	printf("La suma es: %d\n", sum);
	printf("El PpID es: %u\n", ppid);
}
