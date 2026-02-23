#include "square.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free

// Private method: only accessible via the VTable
static void square_draw(void* obj) {
    Square* self = (Square*)obj;
    // Accessing base class fields via self->base
    printf("[Square] %s at (%d, %d) | Side: %.2f\n",
           self->base.name, self->base.x, self->base.y, self->side);
}

// Private VTable for Square
static VTable square_vtable = {
    .draw = square_draw,
    .destroy = free // just free up memory
};

Square* Square_create(int x, int y, float side) {
    Square* sq = (Square*)malloc(sizeof(Square));
    if (sq) {
        sq->base.vptr = &square_vtable; // Wire up the Square behavior
        sq->base.x = x;
        sq->base.y = y;
        sq->base.name = "Square";
        sq->side = side;
    }
    return sq;
}