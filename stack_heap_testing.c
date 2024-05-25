#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void create_object_on_stack(int size) {
    int stack_object[size];  // Allocate an array on the stack
    stack_object[0] = 1;     // Use the stack object to avoid optimization removal
    printf("Stack allocation successful for size %d.\n", size);
    // No explicit deallocation needed for stack allocation
}

void create_object_on_heap(int size) {
    int* heap_object = (int*)malloc(size * sizeof(int));  // Allocate an array on the heap
    assert(heap_object != NULL);  // Ensure allocation was successful
    heap_object[0] = 1;           // Use the heap object to avoid optimization removal
    printf("Heap allocation successful for size %d.\n", size);
    free(heap_object);            // Deallocate the heap memory
    printf("Heap deallocation successful for size %d.\n", size);
}

void test_stack_allocation() {
    create_object_on_stack(1024);  // Test stack allocation
    printf("Test stack allocation passed.\n");
}

void test_heap_allocation() {
    create_object_on_heap(1024);  // Test heap allocation
    printf("Test heap allocation passed.\n");
}

int main() {
    printf("Running memory allocation tests...\n");

    // Set the desired number of iterations
    int num_iterations = 2;

    // Run the test for the specified number of iterations
    for (int i = 0; i < num_iterations; i++) {
        printf("Iteration %d:\n", i + 1);
        test_stack_allocation();
        test_heap_allocation();
    }

    printf("Memory allocation tests completed.\n");
    return 0;
}