## Homework 6

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

If a program writes a new value into the program counter then the flow of execution jumps to another location in the program.

2) What is the fundamental problem caches are meant to solve?

The fundamental problem that caches are meant to solve is that most current desktop computers can initiate a new instruction every .5 nanoseconds but can only transfer data to and from memory every 10 nanoseconds. If the CPU had to wait 10 nanoseconds to fetch the next instruction from memory and another 10 nanoseconds to load the data, programs would take far longer than necessary to run.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

with hit rate 50%: access time = .5*1 ns + .5*10 ns = 5.5 ns

with hit rate 90%: access time = .9*1 ns + .1*10 ns = 1.9 ns

4) The book gives several examples of programming language features, like loops, that tend
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?
Or counter-examples that might decrease locality?

Often, many different functions operate on the same variable, one after the other, giving a pattern of temporal locality. A program that creates and operates on many unique variables and then does not repeat any of the variables or use them again would be a counter-example of code that has very little locality.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

No, because for a program to be "cache aware," its algorithms must be tailored to the size of the cache, the block size, and other hardware characteristics. Refactoring the program to improve locality is a step in the right direction, but until you take the hardware makeup into account and start designing with specific sizes and characteristics in mind, your program is not truly "cache aware."

left off at beginning of section 7.6

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?
