*This activity has been created as part of the 42 curriculum by ngrinchu.*
# Get Next Line
A C project exploring static variables and file descriptors.

## Description
Get Next Line is a C programming project developed as part of the 42 curriculum.
The goal is to implement a function that reads and returns one line at a time from a file descriptor.
The project focuses on file descriptors, static variables, dynamic memory allocation, and file reading with the read() system call.

### Function Prototype
```bash
char *get_next_line(int fd);
```

The function returns:

A dynamically allocated string containing the next line, including the newline character (\n) when present.

NULL when the end of the file is reached and no data remains, or when an error occurs.

## Instructions
### Compilation
The project can be compiled with a custom BUFFER_SIZE:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    main.c get_next_line.c get_next_line_utils.c
```

main.c is a separate test program and is not part of the required project files.

The BUFFER_SIZE macro determines the maximum number of bytes requested by each read() call.

The project also supports compilation without the -D BUFFER_SIZE flag by using a default value defined in the header.

### Usage
Include the header file:
```bash
#include "get_next_line.h"
```
Call get_next_line(fd) repeatedly to read a file line by line.

Each returned line is dynamically allocated and must be freed by the caller.

The function can be used with regular files and standard input.

## Resources
- [File Descriptors in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)

## Resources

- [File Descriptors in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/) — Understanding file descriptors and file operations in C.
- [Understanding Important System Calls in C](https://medium.com/@noransaber685/understanding-important-system-calls-in-c-fork-open-read-close-chdir-getline-and-access-2836cc761b17) — An overview of system calls, including open(), read(), and close().
## Resources

- [File Descriptors in C — Codequoi](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/) — Understanding file descriptors and file operations in C.
- [Understanding Important System Calls in C — Medium](https://medium.com/@noransaber685/understanding-important-system-calls-in-c-fork-open-read-close-chdir-getline-and-access-2836cc761b17) — An overview of system calls, including open(), read(), and close().
- [Static Variables in C — GeeksforGeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/) — Understanding static variables, their lifetime, scope, and value preservation between function calls.

AI Usage  
AI tools were used to clarify C programming concepts encountered in technical articles, explore edge cases, and discuss and improve testing strategies.

## Algorithm and Design Choices

I use a static structure (`state`) containing three fields: `rest`, `capacity`, and `position`. This allows the function to preserve unread data and buffer information between calls.

Initially, the capacity of `rest` is set to `BUFFER_SIZE`. When more space is needed, the capacity is doubled to reduce frequent memory reallocations and unnecessary copying.

When a newline is found in `rest`, the function extracts the complete line and shifts the remaining characters to the beginning of the buffer. This allows the allocated memory to be reused without creating a new buffer for the remaining data.

This approach improves memory management and makes processing long lines more efficient.

### Algorithm Flowchart

The flowchart below illustrates how `get_next_line()` processes data, checks for newline characters, handles reading errors and end-of-file conditions, and returns one line at a time while preserving unread data for subsequent calls.

![Get Next Line Flowchart](https://github.com/GrinchukNadia/c_line/tree/main/img/diagram.png)