#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

// --- "Class" Square, inherits Shape ---
typedef struct {
    Shape base;  // Embed the basic structure
    float side;  // Square-specific data
} Square;

// "Constructor" for Square objects.
Square* Square_create(int x, int y, float side);

#endif // SQUARE_H