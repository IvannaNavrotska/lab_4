#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Unit test for malloc and free with an integer
bool test_malloc_free_int() {
    int* ptr = (int*)malloc(sizeof(int));
    assert(ptr != NULL && "Memory allocation failed");
    *ptr = 42; // Assign a value to the allocated memory
    bool result = (*ptr == 42);
    free(ptr); // Free the allocated memory
    return result;
}

// Unit test for malloc and free with an array
bool test_malloc_free_array() {
    size_t array_size = 5;
    int* array = (int*)malloc(array_size * sizeof(int));
    assert(array != NULL && "Memory allocation failed");
    for (size_t i = 0; i < array_size; ++i) {
        array[i] = (int)i; // Assign values to the array
    }
    bool result = true;
    for (size_t i = 0; i < array_size; ++i) {
        assert(array[i] == (int)i && "Array value assignment failed");
    }
    free(array); // Free the allocated memory
    return result;
}

// Unit test for malloc and free with a struct
typedef struct {
    int x;
    int y;
} Point;

bool test_malloc_free_struct() {
    Point* p = (Point*)malloc(sizeof(Point));
    assert(p != NULL && "Memory allocation failed");
    p->x = 3;
    p->y = 4;
    bool result = (p->x == 3 && p->y == 4);
    free(p); // Free the allocated memory
    return result;
}

// Main function to run the tests
int main() {
    if (test_malloc_free_int()) {
        printf("Test malloc_free_int passed\n");
    } else {
        printf("Test malloc_free_int failed\n");
    }

    if (test_malloc_free_array()) {
        printf("Test malloc_free_array passed\n");
    } else {
        printf("Test malloc_free_array failed\n");
    }

    if (test_malloc_free_struct()) {
        printf("Test malloc_free_struct passed\n");
    } else {
        printf("Test malloc_free_struct failed\n");
    }

    return 0;
}
