#include "shape.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free

// Private method: only accessible via the VTable
static void shape_draw(void* obj) {
    Shape* self = (Shape*)obj;
    printf("[Shape] %s at (%d, %d)\n", self->name, self->x, self->y);
}

// Global VTable for the base class
// Only visible inside this file
static VTable shape_vtable = {
    .draw = shape_draw,
    .destroy = free // just free up memory
};

Shape* Shape_create(int x, int y) {
    Shape* s = (Shape*)malloc(sizeof(Shape));
    if (s) {
        s->vptr = &shape_vtable; // Link to base behavior
        s->x = x;
        s->y = y;
        s->name = "Generic Shape";
    }
    return s;
}

// --- Dynamic Dispatch Logic ---

void call_draw(Shape* s) {
    // This is where "Late Binding" happens
    if (s && s->vptr && s->vptr->draw) {
        s->vptr->draw(s);
    }
}

void Shape_destroy(Shape* s) {
    // This is the "Virtual Destructor" call
    if (s && s->vptr && s->vptr->destroy) {
        s->vptr->destroy(s);
    }
}