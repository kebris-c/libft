# libft

libft is a custom C library that reimplements standard C functions and adds additional utility functions to streamline future projects. It serves as a foundation for other projects, providing reusable headers and functions for things like string manipulation, memory management, and I/O operations.

🧠 Objective

The goal of libft is to:

Reimplement standard C library functions from scratch.

Learn and apply memory management, pointers, and algorithmic thinking in C.

Provide a reliable set of functions for future projects, such as ft_printf, get_next_line, or pipex.

Continuously expand with new functions and utilities over time.

⚙️ Usage Compilation

Compile the library with:

make

This will generate the static library libft.a.

Example #include "libft.h" #include <stdio.h>

int main(void) { char *s = ft_strdup("Hello, libft!"); if (!s) return 1;

printf("%s\n", s);
free(s);
return 0;
}

Link the library when compiling your programs:

gcc main.c libft.a

🔧 Features

Reimplementation of standard functions: ft_strlen, ft_strcpy, ft_memset, ft_atoi, etc.

Additional utility functions: linked lists, memory manipulation, string utilities, and more.

Works as a base library for other projects.

Designed to expand over time, adding new functions as needed.

🧹 Makefile Rules Command Description make Compile the library make clean Remove object files make fclean Remove objects and the library make re Rebuild everything make help Show a brief help hint of available rules ⚡ Key Points

Provides a consistent and reliable set of functions for all your C projects.

Written to comply with the 42 Norm.

Continuously updated with new functions to improve usability and coverage.

👨‍💻 Author

By kebris-c
