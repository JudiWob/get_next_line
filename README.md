# get_next_line

⭐ Validated with 100%

🧠 A function that reads a file line by line — part of the 42 curriculum.

## 📚 About

**get_next_line** is a foundational project at 42 designed to deepen your understanding of file I/O in C. 

The goal is to write a function ```char *get_next_line(int fd);``` that reads from a file descriptor and returns the next line from a file each time it's called.

The function has to work with a ```#define BUFFER_SIZE``` that dictates how many bites get read when calling ```read()``` function.

This adds the difficulty in the sense that: Depening on the number of characters per line and BUFFER_SIZE, a read call might read too little or too many characters!

To solve this, while reading into a ```char *buffer``` of size (BUFFER_SIZE + 1) you need to check for a '/n' character.

If no '/n' found, you need to store content of ```char *buffer``` and in a new string, and read into ```char *buffer``` again until you find '/n'. 

Potential "leftover" characters after '\n' need to be stored in a static char, otherwise if ```char *get_next_line(int fd);``` gets called again, they will be lost,
as this is the way ```read()``` works. 


This project emphasizes buffer management, memory allocation, string manipulation, and handling multiple file descriptors simultaneously.

##  🎯Objectives

- Create a function that returns the next line from a file each time it's called.
- Learn how to open and read from a file, the concept of buffering and static variables.
- Manage memory efficiently and prevent leaks.
- Implement robust error handling and edge case management.

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);

```
✅ Allowed functions

read, malloc, free
