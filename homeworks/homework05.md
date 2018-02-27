## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

It will have more zeros at the beginning and be signed as a positive number.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

?? 12 in binary = 1100; 3 in binary is 11. Two's complement representation of 12 would be 00011.
We could use 12^3 to find this by flipping all the bits.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

?? It is easier to store and unpack these values if we do it with a bias. Also this is how we allocate
space for when numbers are much larger.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

Positive 13 is 1.101*2^3 so -13 would be 1.0010*2^4. If we accidentally interpreted this value as an integer in
base 10 we would get 16.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

A space has the value of 32 which is the sixth bit so you can flip the case of a letter by doing letter ^ " ".
