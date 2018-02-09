## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits are needed to specify a letter because 2^6 > 33 and a given number of bits, b, can
specify 2^b different values. Unfortunately, 5 bits can specify only 32 values, and since
there are 33 letters in the Georgian alphabet, you will need the 6th bit to specify 33
different letter values.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 = 4294967296 different characters can be represented with 32 bits.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

Memory is volatile and lost when a computer is shut down while storage is non volatile and includes
files on a hard disk drive or solid state drive that can be used for long term storage.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is a gibibyte (binary unit, used to measure memory), which is 2^30 bytes, while a GB is a
gigabyte (decimal unit, used to measure disk drives), which is 10^9 bytes. The percentage difference
in their sizes is about 7.1%.

5) How does the virtual memory system help isolate processes from each other?

The virtual memory system helps to isolate processes from each other by not allowing a process to
map to the same physical memory as another process. Since physical memory is allocated to each process
individually and each processes virtual addresses' map to physical addresses in the memory allocated
for that process, each process is able to stay isolated from each other in memory.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

I think the stack and the heap are located at opposite ends of the address space because the heap contains
segments of memory that are allocated at runtime and therefore space needs to be left for the heap to grow
up while the stack contains local variables and parameters and also needs room to expand down.

7) What Python data structure would you use to represent a sparse array?

A dictionary in Python might be used to represent a sparse array.

8) What is a context switch?

A context switch is a mechanism that allows an operating system to interrupt a running process, save its
state, and then run another process.
