#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "intlist.h"

typedef struct node {
  int val;
  struct node* next;
} Node;

struct intlist {
  Node* head;
  Node* tail;
  int listSize;
};

IntList* ilCreate()
{
  IntList *il = malloc(sizeof(IntList));
  il->head = NULL;
  il->tail = NULL;
  il->listSize = 0;
}

void ilAppend (IntList *il, int val)
{
  Node *n = malloc(sizeof(Node));
  n->val = val;
  n->next = NULL;

  if (il->listSize > 0) {
    il->tail->next = n;
    il->tail = n;
  }
  else {
    il->head = n;
    il->tail = n;
  }

  il->listSize ++;
}
  
IntList* ilCopy (IntList *il)
{
  IntList *c;
  Node *n;
  
  c = ilCreate();
  
  n = il->head;
  while (n != NULL) {
    ilAppend(c, n->val);

    n = n->next;
  }

  return c;
}

void ilPrint (IntList *il)
{
  int i = 0;
  Node *n = il->head;

  while (n != NULL) {
    printf ("%d: %d\n", i, n->val);
    i++;
    n = n->next;
  }
}

int ilFind (IntList *il, int val)
{
  int i = 0;
  Node *n = il->head;
  while (n != NULL) {
    if (n->val == val) {
      return i;
    }
    i++;
    n = n->next;
  }
  return -1;  
}

int ilGet (IntList *il, int pos)
{
  Node *n = il->head;
  int i;
  
  if ((pos < 0) || (pos >= il->listSize))
    return INT_MIN;

  for (i=0; i< pos; i++)
    n = n->next;
  
  return n->val;
}

int ilInsert (IntList *il, int pos, int val)
{
  Node *newNode, *n;
  int i;

  if ((pos < 0) || (pos >= il->listSize))
    return INT_MIN;

  newNode = malloc (sizeof(Node));
  newNode->val = val;

  if (pos == 0) {
    newNode->next = il->head;
    il->head = newNode;
  }
  else {
    n = il->head;

    for (i=0; i<pos-1; i++)
      n = n->next;

    newNode->next = n->next;
    n->next = newNode;
  }
  il->listSize++;
  
  return 0;
}

int ilSize (IntList *il)
{
  return il->listSize;
}

int ilDelete (IntList *il, int pos)
{
  Node *n, *del;
  int i;

  if ((pos < 0) || (pos >= il->listSize))
    return -1;

  if (il->listSize == 1) {
    il->head = NULL;
    il->tail = NULL;
  }
  else if (pos == 0) {
    il->head = il->head->next;
  }

  else {
    n = il->head;

    for (i=0; i<pos -1; i++)
      n = n->next;

    n->next = n->next->next;
    
    if (n->next == NULL)
      il->tail = n;
  }

  il->listSize--;

  return 0;
}
  