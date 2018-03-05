## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

I would expect calloc and realloc to take time proportional to the size of
the allocated chunk while I would expect free and malloc to take only constant time.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

You might get a segmentation fault or more likely, you will get no error but will get
whatever value happened to be stored at a particular location before.

b) Writing to unallocated memory.

Later, the memory might be allocated for something else and then output unpredictable
results when it is read. Additionally, you might mangle data structures for malloc and
free and then cause these functions to fail later in inexplicable ways.

c) Reading from a freed chunk.

The result will be unpredictable because you might get the old value or you might
get some new value that has now been written to that space since it has been freed
up for future allocation.

d) Writing to a freed chunk.

If you write to a freed chunk, what you write might get overwritten because the chunk
is free to be allocated for something else the next time malloc is called.

e) Failing to free a chunk that is no longer needed.

You will have a memory leak and if the program runs for a long time, the system might
run out of physical memory and then malloc will fail and return NULL if the system
does not have any virtual memory.


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

It looks like on my machine currently the processes which are using up the most memory are google
chrome and atom.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

Allocating a large number of small chunks is not good because the minimum chunk size on most systems is
16 bytes and allocating a large number of small chunks wastes memory if you are not using all 16 bytes.
You can mitigate this problem by allocating space in arrays for large numbers of small structures.

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
