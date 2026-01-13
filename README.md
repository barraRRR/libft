# libft

_This project was developed as part of the 42 curriculum by jbarreir._

## Description

In this project, we recreate a subset of functions from the standard C library (**libc**) as an exercise to better understand their behavior and internal implementation.

The project is divided into three parts:

- **Part I**: Reimplementation of selected libc functions, strictly following their prototypes and the behavior described in the `man` pages.
- **Part II**: Additional utility functions that are either not part of libc or are implemented differently.
- **Part III**: Functions to manipulate singly linked lists.

The result is a static C library that can be reused in future projects.

## Instructions

A **Makefile** is provided to compile the library. Its main features are:

- Compilation using `cc` with the flags `-Wall -Wextra -Werror`.
- Uses the variable **AR = ar rcs** to create the static library.
- Uses the variable **RM = rm -f** to remove generated files.
- Implements the standard rules: `all`, `clean`, `fclean`, and `re`.

### Compilation

To compile the library, simply run:

``` bash
make
```
This will generate the static library file:
```` text
libft.a
````
### Usage

To use libft in your own project:
1. Include the header file in your source code:
```
#include "libft.h"
````
2. Compile your .c files while linking the static library:
````
cc -Wall -Wextra -Werror *.c -L. -lft
````

## Resources
- man libc
- man 3 malloc
- man 3 free
- The GNU C Library Documentation
- 42 intra documentation and subject PDF