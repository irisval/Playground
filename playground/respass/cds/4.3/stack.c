#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

typedef struct node {
  int val;
  struct node* next;
} Node;

struct stack {
  int stackSize;
  Node* head;
};

Stack* createStack ()
{
	Stack *stack = malloc(sizeof(Stack));
	stack->head = NULL;
	stack->stackSize = 0;


	/* implement me */
}

void push (Stack *s, int val)
{
	Node *n = malloc(sizeof(Node));
	n->val = val;
	n->next = stack->head;

	stack->head = n;
	stack->stackSize++;
	/* implement me */
}

int pop (Stack *s)
{
	if (stack->stackSize > 0) {
		int value = stack->val;
		stack->head = stack->next;
		stack->stackSize--;
		return value;
	} 
	return INT_MIN;
	/* implement me */
}

int isStackEmpty (Stack *s)
{
	if (stack->stackSize == 0) 
		return 1;
	return 0;
	/* implement me */
}

int getStackSize(Stack *s)
{
	return stackSize;
	/* implement me */
}

