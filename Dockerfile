FROM gcc:latest

WORKDIR /lab_4

COPY value_reference_testing.c .
COPY stack_heap_testing.c .
COPY malloc_free_testing.c .

RUN gcc -o value_reference_testing value_reference_testing.c
RUN gcc -o stack_heap_testing stack_heap_testing.c
RUN gcc -o malloc_free_testing malloc_free_testing.c

CMD ["/bin/bash", "-c", "./value_reference_testing && ./stack_heap_testing && ./malloc_free_testing"]
