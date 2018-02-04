/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    int var3 = 8;
    void *p = malloc(128);
    void *p2 = malloc(128);
    void *q = malloc(20);
    void *q2 = malloc(20);
    char *s = "Literal string";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of var3 is %p\n", &var3);
    printf ("Address of p is %p\n", p);
    printf ("Address of p2 is %p\n", p2);
    printf ("Address of q is %p\n", q);
    printf ("Address of q2 is %p\n", q2);
    printf ("Address of s is %p\n", s);

    return 0;
}
