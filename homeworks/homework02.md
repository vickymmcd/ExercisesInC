## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

(change to make it not from book later) A real world example of virtualization is an inter library collaboration where libraries
can borrow books from each other. A person can request a book from the library and it can either come from a shelf at the local
library or from another library's collection. Abstractly there is an illusion that the library has every book in the world while
in reality the library might only have a small collection.

2. What is the difference between a program and a process?

A process is a software object that represents a specific portion of a running program and isolates each running program from others.
A process runs a program.

3. What is the primary purpose of the process abstraction?

The primary purpose of process abstraction is for isolation so that programmers do not have to think about every possible interaction.

4. What illusion does the process abstraction create?

Process abstraction creates the illusion that all these processes are isolated and separate from each other. This allows people to
multi task and switch between processes, feel that each process has its own memory, and work on one device that must in reality
be controlling and communicating with many different processes at once.

5. What is the kernel?

The kernel is the part of the operating system responsible for core capabilities like creating threads.

6. What is a daemon?

A daemon is a process that runs in the background and provides operating system services.
