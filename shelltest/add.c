#include "main.h"

void main(void)
{
	int a = 10, b = 5, sum = a + b;
	pid_t pid = getpid();

	printf("La suma es: %d\n", sum);
	printf("El PID es: %u\n", pid);
}
