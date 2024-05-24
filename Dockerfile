FROM gcc:latest

WORKDIR /lab_4

COPY . .

RUN gcc -o value_reference_testing value_reference_testing.c
RUN gcc -o stack_heap_testing stack_heap_testing.c

CMD ["sh", "-c", "./value_reference_testing && ./stack_heap_testing"]