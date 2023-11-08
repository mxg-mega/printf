#include "main.h"
#include <stdio.h>

int main(void)
{
	int a;

	a = _printf("%s %c is C fun 100% ?\n", "i mean", 'y');
	printf("%d\n", a);
	return (0);
}

