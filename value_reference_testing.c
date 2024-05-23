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


void run_test(void (*test_func)(), const char* test_name) {
    printf("Running %s ", test_name);
    fflush(stdout);
    test_func();
    printf("passed\n");
}

int main() {
    run_test(test_pass_by_reference, "test_pass_by_reference");
    run_test(test_pass_by_value, "test_pass_by_value");

    return 0;
}