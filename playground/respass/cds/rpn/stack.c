#define STACK_SIZE 100
#include <stdio.h>
#include <math.h>
#include "stack.h"

double stack[STACK_SIZE];
int sp=0;


/*
 * Pushes character c onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs.  (Stack full).
 */
int push (double c)
{
	if (sp < STACK_SIZE) {
		stack[sp++] = c;
		return 0;
	}
	return -1;
}

/*
 * Pops next character off the stack.
 * Returns the char if successful.
 * Returns -1 if an error occurs.  (Stack empty).
 */
double pop ()
{
	if (sp > 0)
		return stack[--sp];
	return NAN;
}

int isStackEmpty ()
{
	if (sp == 0)
		return 1;
	return 0;
}

int getStackSize()
{
	return sp;
}

void emptyStack() 
{
	sp = 0;
}

