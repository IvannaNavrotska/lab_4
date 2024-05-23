# lab_4
memory management using the C programming language

# Value and reference types. Garbage collector

**Value types**: the variables of these data types directly contain values. When we assign a value type to another variable, a copy of the value is created and changing the new variable doesn’t affect the original variable. 

**Reference types**: the variables of these data types store the reference (address) where the value is being stored. They contain a pointer to another memory location that holds the data. When we assign a reference type to another variable, both variables refer to the same data in memory, but changes made through one variable will be reflected in the other.

**Garbage collector** - a form of automatic memory management, its main purpose is to reclaim memory that is no longer in use by the program, preventing memory leaks and optimizing the utilization of system resources. 

There are value and reference types in C, but it doesn’t have reference types in the same way that is in higher-level languages. But in order to achieve similar behaviour there are pointers -  variables which contains the memory address of another variable which effectively allows it to reference another variables value. Also C doesn’t have garbage collector, instead of it there are memory management mechanisms like malloc() and free() functions. The free() is used to release memory when it’s no longer required, and the malloc() - to allocate memory dynamically during runtime. 

**Stack and heap in C**

**Stack:**
The stack has a fixed size limit, so when we declare variables on the stack, their memory is automatically reclaimed when they go out of scop
When we declare a variable inside a function, it's typically allocated on the stack
Accessing variables on the stack is generally faster than accessing variables on the heap

**Heap:**
Memory allocation on the heap is dynamic, it means we can request memory at runtime
The heap typically has more memory available compared to the stack, but it's not as fast for allocation and deallocation
Accessing variables on the heap is slower than accessing variables on the stack due to the need for dynamic memory management.
