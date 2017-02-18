#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main()
{
	Point *p1;
	Point *p2;

	char temp1[15];

	p1 = createPoint (3, 7);
	p2 = createPoint (4, 5);

	movePoint (p1, 10, 3);
	dilatePoint (p2, 2);

	printf ("Point 1: %s\n", pointToString(p1, temp1));
	printf ("Point 2: %s\n", pointToString(p1, temp1));
	}