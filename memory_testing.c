#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Function to increment a value passed by reference
void incrementByRef(int *num) {
    (*num)++;
}

// Function to increment a value passed by value
int incrementByVal(int num) {
    return num + 1;
}

// Custom type: Point
typedef struct {
    int x;
    int y;
} Point;

// Function to create a Point on the stack
Point createPointOnStack(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

// Function to create a Point on the heap
Point* createPointOnHeap(int x, int y) {
    Point* p = (Point*)malloc(sizeof(Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void test_pass_by_reference() {
    int x = 5;
    incrementByRef(&x);
    assert(x == 6); // Assert x has been incremented
}

void test_pass_by_value() {
    int y = 5;
    int result = incrementByVal(y);
    assert(result == 6); // Assert the returned value is incremented
    assert(y == 5);      // Assert the original value remains unchanged
}

void test_create_point_on_stack() {
    Point p = createPointOnStack(1, 2);
    assert(p.x == 1); // Assert x is correctly set
    assert(p.y == 2); // Assert y is correctly set
}

void test_create_point_on_heap() {
    Point* p = createPointOnHeap(3, 4);
    assert(p != NULL); // Assert memory allocation succeeded
    assert(p->x == 3); // Assert x is correctly set
    assert(p->y == 4); // Assert y is correctly set
    free(p);           // Deallocate memory
}

void run_test(void (*test_func)(), const char* test_name) {
    printf("Running %s ", test_name);
    fflush(stdout);
    test_func();
    printf("passed\n");
}

int main() {
    run_test(test_pass_by_reference, "test_pass_by_reference");
    run_test(test_pass_by_value, "test_pass_by_value");
    run_test(test_create_point_on_stack, "test_create_point_on_stack");
    run_test(test_create_point_on_heap, "test_create_point_on_heap");

    return 0;
}