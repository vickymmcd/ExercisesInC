## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

Each thread has its own stack so threads can call functions without interfering with each other and without accidentally accessing another thread's local variables.

2) What does the gcc flag `-lpthread` do?

The gcc flag `-lpthread` compiles your code so that it is linked with the Pthread library.

3) What does the argument of `pthread_exit` do?

The argument to pthread_exit can be used to pass a value to the thread that joins with the thread which is exiting.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

Any thread can join with any other thread, it is just more common for a parent thread to be joining with a child thread. If a thread tries to join a thread it did not create then it will simply wait for the thread it is joining with to complete before continuing.

5) What goes wrong if several threads try to increment a shared integer at the same time?

If several threads try to increment a shared integer at the same time then several threads might read the same value before any threads increment it, meaning that the value only goes up by one even though several threads have tried to increment it.

6) What does it mean to "lock a mutex"?

Locking a mutex bars all other threads from running so that one thread can finish executing before it unlocks the mutex and allows another thread to execute.
