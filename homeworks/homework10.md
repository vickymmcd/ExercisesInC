## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

It means that both threads can access that data structure at the same time.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

In the circular buffer implementation of a queue the maximum number of elements is n-1 in an array of size n
because if we keep adding elements next in catches up with next out and gives the impression of the array
being empty. We add one less element that the size of the array to prevent the misconception that the array
is empty when next in points to next out.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

One sequence of steps that could leave the queue in an inconsistent state would be if an element is added to the
queue then the queue push thread gets interrupted by the queue pop thread, which removes the thing that was just
added and then when the queue push thread continues it will try to increment an element that has now been removed
meaning that it will either throw an error or more likely, increment the wrong element.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

When a thread calls cond_wait it has to unlock the mutex before blocking so that other threads are able to access the queue and change its state. If for example a queue was blocked waiting for it to not be empty and then we never allowed another thread to run and add something to the queue then the queue would never become unblocked.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

We know that the mutex is locked and the condition is probably true but we need to check and make sure the condition is true just in case something happened to make it not true between when it signaled as true and when we were able to lock the mutex back up again.

6) What happens if you signal a condition variable when there are no waiting threads?

If there are no threads waiting on the condition variable then the signal has no effect.

7) Do you have to lock the mutex to signal a condition variable?

No, but cond_wait will lock the mutex after the condition variable has been signaled and then see if the condition is still true after the mutex is locked before continuing.

8) Does the condition have to be true when you signal a condition variable?

Not necessarily. Signaling a condition variable implies that the condition is either true or might be true, but the condition should be checked again after the mutex is locked before continuing.
