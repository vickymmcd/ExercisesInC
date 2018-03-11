/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{
    // I commented it out variables we never used
    // int never_allocated;
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int *array1 = malloc(100 * sizeof (int));
    // int *array2 = malloc(100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    // let's just make sure we read values in the bounds
    read_element(array1, 1);
    read_element(array1, 10);

    // but it does bounds-check dynamic arrays
    //read_element(array2, 2);
    //read_element(array2, 10);

    // and it catches use after free
    // I moved free to be later
    *use_after_free = 17;

    // never_free is definitely lost
    *never_free = 17;

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // don't free things we never allocated
    //free_anything(&never_allocated);

    free(use_after_free);
    free(free_twice);
    free(never_free);
    free(array1);
    // don't free it twice
    //free(free_twice);

    return 0;
}
