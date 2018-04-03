## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

The kernel's most basic task is to handle interrupts which stop the normal instruction cycle and cause the flow of execution to jump to a special section of code called an "interrupt handler."

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The part of the hardware state that is saved by the hardware is the program counter so that the kernel know where to resume.

3) What is the difference between an interrupt and a context switch?

A context switch happens after an interrupt occurs. In a context switch, instead of the kernel resuming the interrupted process, it switches to another process. A context switch is relatively slow and the kernel generally sets a hardware time that causes an interrupt after a certain amount of time.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

An event that might cause a process to move from the blocked state to the ready state is a disk request. When the disk request completes, it causes an interrupt, which figures out which process was waiting for the request to finish and switches its state from blocked to ready.

5) Why might a scheduler want to give higher priority to an I/O bound process?

The scheduler might want to give higher priority to an I/O bound process because these types of processes need to read data from a network or disk and should get started as soon as possible since they don't need much CPU time but depend on outside factors and might be blockers for other processes.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical;
this is really how I make French toast.)

Put 8 slices on the griddle for 5 minutes. Flip all 8 slices and cook the other side of those 8 for 5 minutes. Put the last 4 on the griddle and cook for 5 minutes each side for a total of 10 more minutes. All 12 slices are done cooking in 20 minutes.
