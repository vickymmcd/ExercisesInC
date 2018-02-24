## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/vickymmcd/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically
true about files systems but not true of their implementations.

Abstractly file systems are a mapping from a file name to that file's contents where you can think
of the names as keys and the contents as values. It is logically true that file systems are byte
based but in reality persistent storage is block based so the implementation has to translate
byte based file operations into block based operations on storage devices.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

The information that I imagine would be stored in the OpenFileTableEntry would be what files are
currently open, whether they are open for reading or writing, and pointers to how much of each file
has been read or written to.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Operating systems deal with the relatively slow performance of persistent storage using block transfers, prefetching
(where the operating system loads additional blocks before they are requested), buffering (storing things in memory
and writing to disk later), and caching (keeping a copy of the block in memory).

4) Suppose your program writes a file and prints a message indicating that it is done writing.
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the
file you wrote is not there.  What happened?

Your computer was dealing with the relatively slow performance of persistent storage by using a process called
buffering where it stored the data in memory with the plan of writing it to the disk later. When your computer crashed
the data that was stored in memory was lost and was never written to the disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

One advantage of a File Allocation Table over a UNIX inode is that larger files can more easily be stored using a
FAT where each block simply points to the next block, while UNIX inodes have a restricted number of blocks that any
given file can use. An advantage of inodes over a FAT is that they reside on the disk along with the rest of the data
and fit neatly into disk blocks.

6) What is overhead?  What is fragmentation?

Minimal space overhead means that the data structures used by the allocator should be small, leaving as much space as possible
for the data. If some blocks are unused or partially used, the unused space is called fragmentation.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The "everything is a file" principle is a good idea because it makes life easier for programmers since they only have to learn
one API and can make programs more versatile. It might be a bad idea because it might sometimes cause unpredictable or
potentially buggy behavior in your code if you do not know exactly what format the data is coming in from or going out to is
going to be.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).
