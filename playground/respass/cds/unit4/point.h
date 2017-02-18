#include <stdio.h>

struct point;
/*  Declares a structure that will be defined in point.c 
  By not providing the definition here, we hide the implementation.
*/

typedef struct point Point;
/*  Renames "struct point" to "Point" for convenience.  */

Point* createPoint (float x, float y);
/* Creates a new "Point" object, defined by the coordinates x and y.
   It is the responsibility of the calling code to free the Point
   when done.
   */

void movePoint (Point *p, float dx, float dy);
/* Translates point "p" by dx and dy. */

void dilatePoint (Point *p, float factor);
/* Dilates point "p" about the origin by "factor". */

char* pointToString (Point *p, char out[]);
/* Write a string representation of Point p to "out".
   "out" must be large enough for the sting.  
   10 characters should be plenty in most cases.
   The function returns a reference to out to make printing easier. 
   */
