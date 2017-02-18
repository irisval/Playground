#include <stdio.h>
#include <stdlib.h>

void swap_a (int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_b (int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int arg1 = 15;
	int arg2 = 25;

	printf("Starting values %d, %d\n", arg1, arg2);
	swap_a(arg1, arg2);
	printf("After swap a %d, %d\n", arg1, arg2);
	swap_b(&arg1, &arg2);
	printf("After swap b %d, %d\n", arg1, arg2);
}