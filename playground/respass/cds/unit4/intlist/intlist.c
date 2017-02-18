#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "intlist.h"

struct intlist {
	int size;
	int arraySize;
	int *list;
};

IntList* ilCreate () {
	IntList *il = malloc (sizeof (IntList));
	il->size = 0;
	il->arraySize = 10;
	il->list = malloc (sizeof(int) * il->arraySize);

	return il; 
};


IntList* ilCopy (IntList *il) {
	int i;

	IntList *k = malloc (sizeof (IntList));
	k->size = il->size;
	k->arraySize = il->arraySize;

	k->list = malloc (sizeof(il->list));
	for (i = 0; i < il->arraySize; i++) 
	  {
	  	k->list[i] = il->list[i];
	  }
	return k;
};

void ilExpand (IntList *il)
{

  int *newList;
  int newSize = il->arraySize + 10;
  int i;

  newList = malloc(sizeof(int) * newSize);
  for (i = 0; i < il->arraySize; i++) 
  {
  	newList[i] = il->list[i];
  }

  // if (il->list != NULL)
  // 	free(il->list);
  il->arraySize = newSize;
  il->list = newList;

};

void ilAppend (IntList *il, int val) {
	if (il->size == il->arraySize) {
		ilExpand(il);
	}
	
	il->list[il->size] = val;
	il->size++;
};



int ilDelete (IntList *il, int pos) {
	
	if ((pos < 0) || (pos >= il->arraySize) || il->size == 0)
		return -1;

	int i;	
	for (i = pos; i < il->arraySize; i++) {
		il->list[i] = il->list[i+1]; 
	}
	il->size--;
	return 0;
};

int ilFind (IntList *il, int val) {

	int i;

	for (i=0; i < il->arraySize; i++) {
		if (il->list[i] == val) {
		  return i;
		}
	}
	return -1; 
};

int ilGet (IntList *il, int pos) {
	/******************************
 * Returns the value of the "pos" element in the list.
 * Returns INT_MIN (as defined in limits.h) if "pos" 
 * is not in the list.
 */
	
	int i;
	
	for (i = 0; i < il->arraySize; i++)
		if (i == pos)
			return il->list[i]; 
	return INT_MIN;

};

int ilInsert (IntList *il, int pos, int val) {


	int i;


	if ((pos < 0) || (pos >= il->arraySize))
		return INT_MIN;

	if (il->size == pos)
		ilExpand(il);

	for (i = il->size; i > pos; i--) {
		il->list[i] = il->list[i-1]; 
	}
  il->size++;
	il->list[pos] = val; 
	return 0;
	
}; 

int ilSize (IntList *il) {
	return il->size;
};

void ilPrint(IntList *il) {
  int i;

  for(i = 0;i < il->size; i++)
    printf("%d: %d\n", i, il -> list[i]);
}
//
// // look n
		// 		if ((row - 1 >= 0) && (column < 200)) {
		// 			if (cells[row-1][column])
		// 				neighbors++;
		// 		}
		// 		// look e
		// 		if ((row < 60) && (column + 1 < 200)) {
		// 			if (cells[row][column+1])
		// 				neighbors++;
		// 		}
		// 		// look s
		// 		if ((row + 1 < 60) && (column < 200)) {
		// 			if (cells[row+1][column])
		// 				neighbors++;
		// 		}
		// 		// look w
		// 		if ((row >= 0) && (column - 1 >= 0)) {
		// 			if (cells[row][column-1])
		// 				neighbors++;
		// 		}
		// 		// look ne
		// 		if ((row - 1 >= 0) && (column + 1 < 200)) {
		// 			if (cells[row-1][column+1])
		// 				neighbors++;
		// 		}
		// 		// look nw
		// 		if ((row - 1 >= 0) && (column - 1 >= 0)) {
		// 			if (cells[row-1][column-1])
		// 				neighbors++;
		// 		}
		// 		// look se
		// 		if ((row + 1 < 60) && (column + 1 < 200)) {
		// 			if (cells[row+1][column+1])
		// 				neighbors++;
		// 		}
		// 		// look sw
		// 		if ((row + 1 < 60) && (column - 1 >= 0)) {
		// 			if (cells[row+1][column-1])
		// 				neighbors++;
		// 		}