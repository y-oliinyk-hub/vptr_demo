#ifndef SHAPE_H
#define SHAPE_H

// --- The Virtual Table Contract ---
typedef struct {
    void (*draw)(void* obj);    // Method signature for drawing
    void (*destroy)(void* obj); // Method signature for cleanup
} VTable;

// --- The Base "Class" ---
typedef struct {
    VTable* vptr;      // Pointer to the virtual table (Dynamic Dispatch)
    int x, y;          // Common data: coordinates
    const char* name;  // Common data: label
} Shape;

// Constructor for a generic Shape
Shape* Shape_create(int x, int y);

// Dynamic Dispatchers (The "Virtual" calls)
void call_draw(Shape* s);
void Shape_destroy(Shape* s);

#endif // SHAPE_H