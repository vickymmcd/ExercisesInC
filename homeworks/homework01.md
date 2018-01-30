## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex01)


### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages often support dynamic types where you do not need to know the type of a variable until the program is running and therefore do not need to declare a variable's type when you initialize it while compiled languages are usually limited to static types where you need to specify a variable's type when it is initialized and is checked at compile time.

2) Name two advantages of static typing over dynamic typing.

One advantage of static typing over dynamic typing is that because variables are declared as certain types, the compiler can check whether these variables are used correctly before the program starts executing, meaning that errors can be found more quickly and in parts of the program that have never actually run. Additionally, declaring types at compile time saves space because variable names do not need to be saved in memory while the program runs.

3) Give an example of a static semantic error.

An example of a static semantic error is an error that comes up during compilation if a function is called with the wrong type or number of arguments or if a variable or value has the wrong type.

4) What are two reasons you might want to turn off code optimization?

You might want to turn off optimization because it could cause a subtle bug to appear or disappear. Also, turning off optimization makes debugging easier.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The `-S` flag tells `gcc` to compile the program and create human readable assembly code. `gcc` is configured to generate code for the machine you are running on meaning you will see different results on different computers.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

If you spell a function name wrong you will get a message from the linker whereas if you spell a variable name wrong you will get a message from the compiler.

7) What is a segmentation fault?

A segmentation fault happens when you try to read or write an incorrect location in memory.
