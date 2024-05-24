FROM gcc:latest

WORKDIR /lab_4

COPY lab_4/*.c ./

RUN for file in *.c; do gcc -o "${file%.c}" "$file"; done

CMD CMD ["sh", "-c", "./value_reference_testing && ./stack-heap_testing && ./malloc_free_testing"]