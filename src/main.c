#include "shape.h"
#include "circle.h"
#include "square.h"

#include <stdio.h>

int main() {
    // Array of base class pointers
    Shape* shapes[3];

    shapes[0] = (Shape*)Circle_create(10, 20, 5.5f);
    shapes[1] = (Shape*)Square_create(50, 50, 10.0f);
    shapes[2] = Shape_create(0, 0);

    printf("--- Polymorphic Drawing ---\n");
    for (int i = 0; i < 3; i++) {
        if (shapes[i]) call_draw(shapes[i]);
    }

    printf("\n--- Virtual Cleanup ---\n");
    for (int i = 0; i < 3; i++) {
        Shape_destroy(shapes[i]);
    }

    return 0;
}