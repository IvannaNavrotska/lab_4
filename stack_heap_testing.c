#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototype
void createOnStack();

// Global variable to keep track of allocated memory size
size_t allocatedMemory = 0;

// Function to allocate memory and update the counter
void* myMalloc(size_t size) {
    allocatedMemory += size;
    return malloc(size);
}

// Function to deallocate memory and update the counter
void myFree(void* ptr, size_t size) {
    allocatedMemory -= size;
    free(ptr);
}

// Function to test memory increase when allocated through myMalloc
bool test_memory_increase() {
    size_t initialMemory = allocatedMemory;
    int* heapObject = (int*)myMalloc(sizeof(int));
    size_t finalMemory = allocatedMemory;
    myFree(heapObject, sizeof(int));
    
    return finalMemory > initialMemory;
}

// Function to test memory decrease when deallocated through myFree
bool test_memory_decrease() {
    int* heapObject = (int*)myMalloc(sizeof(int));
    size_t initialMemory = allocatedMemory;
    myFree(heapObject, sizeof(int));
    size_t finalMemory = allocatedMemory;
    
    return finalMemory < initialMemory;
}

// Function to test stack memory
bool test_stack_memory() {
    size_t initialMemory = allocatedMemory;
    createOnStack();
    size_t finalMemory = allocatedMemory;

    return finalMemory == initialMemory;
}

// Function to create an object on the stack
void createOnStack() {
    int stackObject[100000]; // Allocate a large object on the stack
    printf("Object created on the stack\n");
}

// Function to create an object on the heap
void createOnHeap() {
    int* heapObject = (int*)myMalloc(sizeof(int)); // Object created on the heap
    printf("Object created on the heap\n");
    myFree(heapObject, sizeof(int)); // Freeing the allocated memory
}

int main() {
    bool memoryIncreasePassed = test_memory_increase();
    bool memoryDecreasePassed = test_memory_decrease();
    bool stackMemoryPassed = test_stack_memory();
    
    if (memoryIncreasePassed) {
        printf("Memory increase test passed\n");
    } else {
        printf("Memory increase test failed\n");
    }
    
    if (memoryDecreasePassed) {
        printf("Memory decrease test passed\n");
    } else {
        printf("Memory decrease test failed\n");
    }
    
    if (stackMemoryPassed) {
        printf("Stack memory test passed\n");
    } else {
        printf("Stack memory test failed\n");
    }

    // Call createOnHeap to ensure its functionality is tested
    createOnHeap();

    return 0;
}
