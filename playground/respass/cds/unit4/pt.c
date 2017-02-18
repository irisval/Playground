#include <stdio.h>

struct point {
	int x;
	int y;
};

typedef struct point Point;

void printPoint (Point p)
{
	printf("(%d, %d)", p.x, p.y);
}

int main()
{
	Point p1, p2;

	p1.x = 14;
	p1.y = 23;

	p2.x = 9;
	p2.y = 99;

	printPoint (p1);
	printf ("\n");
	printPoint (p2);
}


