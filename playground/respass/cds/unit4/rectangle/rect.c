#include <stdio.h>
#include "rect.h"
#include <stdlib.h>


Rect* createRect (float x1, float y1, float x2, float y2) {
  Rect* r = malloc (sizeof (Rect));

  (r->pt1).x = x1;
  (r->pt1).y = y1;
  (r->pt2).x = x2;
  (r->pt2).y = y2;

  return r;
}

   
Rect* copyRect (Rect* r) {
  Rect* a = malloc (sizeof (Rect));
  (a->pt1).x =  (r->pt1).x;
  (a->pt1).y =  (r->pt1).y;
  (a->pt2).x =  (r->pt2).x;
  (a->pt2).y =  (r->pt2).y;

  return a;
}
   
void move (Rect *r, float dx, float dy) {
  r-> pt1.x += dx;
  r-> pt1.y += dy;
  r-> pt2.x += dx;
  r-> pt2.y += dy;
}

void dilate (Rect *r, float factor) {
  r-> pt1.x *= factor;
  r-> pt2.x *= factor;
  r-> pt1.y *= factor;
  r-> pt2.y *= factor;
}
   
float getWidth (Rect *r) {
  return abs((r->pt1).x -  (r->pt2).x);
}

float getHeight (Rect *r) {
  return abs((r->pt1).y -  (r->pt2).y);
}

float getArea (Rect *r) {
  return getWidth(r) * getHeight(r);
}

float getPerimeter (Rect *r) {
  return (getWidth(r) + getHeight(r)) * 2;
}

char* toString (Rect *r, char out[]) {
   
  sprintf (out, "Rectangle: (%.1f,%.1f); (%.1f,%.1f)",  (r->pt1).x,  (r->pt1).y, (r->pt2).x,  (r->pt2).y);
  return out;
}
