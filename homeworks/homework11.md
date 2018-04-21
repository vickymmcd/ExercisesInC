## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

It is a bad idea to pass `sem_t` as a parameter because its type behaves as a structure so when you assign a variable to it you are making a copy of its contents and the behavior of the copy can be undefined.

2) When you use a Semaphore as a mutex, what should its initial value be?

Its initial value should be 1 to indicate that the mutex is unlocked and that one thread can pass the semaphore without blocking.

3) Can you think of another use for a Semaphore where you might use a different initial value?

You might use an initial value of 0 instead of 1 for a semaphore which you want to be locked initially in a case where, for example, you want to wait until a connection occurs or a piece of data is grabbed before a thread that needs the semaphore can start.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

If the value of queue->spaces is 3 at some point in time then that means that there are 3 empty spaces in the queue meaning that there are 3 threads that can execute queue_pop without blocking.

5) What does it mean if `queue->space` is `-3`?

If the value of queue->spaces is -3 then that means that at least 3 threads have to finish execution before another thread can execute queue_pop.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

Queue_pop no longer has to use queue_empty to check whether the queue is empty because the semaphore keeps track of how many items are in the queue and blocks if the queue is empty.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

You can prove that this is true by implementing a semaphore using condition variables and mutexes.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*,
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf).

Property 3 is that if there are threads waiting on a semaphore when a thread executes signal then one of the waiting threads has to be woken.
