#include "circle.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free

// Private method: only accessible via the VTable
static void circle_draw(void* obj) {
    // Cast the generic pointer to the specific type
    Circle* self = (Circle*)obj;
    printf("[Circle] %s at (%d, %d) | Radius %.2f\n",
            self->base.name, self->base.x, self->base.y, self->radius);
}

// Private VTable for Circle
static VTable circle_vtable = {
    .draw = circle_draw,
    .destroy = free // just free up memory
};

Circle* Circle_create(int x, int y, float radius) {
    Circle* c = (Circle*)malloc(sizeof(Circle));
    if (c) {
        c->base.vptr = &circle_vtable; // Late binding initialization
        c->base.x = x;
        c->base.y = y;
        c->base.name = "Circle";
        c->radius = radius;
    }
    return c;
}

