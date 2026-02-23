#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// --- "Class" Circle, inherits Shape ---
typedef struct {
    Shape base;    // Embed the basic structure
    float radius;  // Circle-specific data
} Circle;

// "Constructor" for creating and initializing Circle objects.
Circle* Circle_create(int x, int y, float radius);

#endif // CIRCLE_H