#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int stackSize = 0;
double* stack = NULL;
int sp=0;

void expand() {
  double* newStack;
  int newSize = stackSize + 10; 
  int i;

  newSize = malloc (sizeof(double) * newSize);

  for (i = 0; i < stackSize; i++) 
  {
    newStack[i] = stack[i];
  }

  if (stack != NULL)
    free(stack);
  stackSize = newSize;
  stack = newStack;


}

int push (double d)
{
  /*  printf ("\nPushing %f.\n", d);*/
  if (sp >= stackSize) {
    expand();
  }

  stack[sp] = d;
  sp++;

  return 0;
}

double pop ()
{
  double pop;
  if (sp == 0) {
    return NAN;
  }
  pop = stack[--sp];
  /*printf("\nPopping %f.\n", pop);*/
  
  return pop;
}


int isStackEmpty ()
{
  if (sp == 0)
    return 1;
  else
    return 0;
}

int getStackSize()
{
  return sp;
}

void emptyStack()
{
  sp=0;
}