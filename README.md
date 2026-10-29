*This project has been created as part of the 42 curriculum by ael-barh.*

# Libft

## Description

**Libft** is the first project of the 42 common core. The goal is to build, from scratch, your own C static library (`libft.a`) that re-implements a set of standard C library functions, adds a few useful utility functions, and provides basic linked-list manipulation. This library is meant to be reused and extended in all later 42 projects.

The project teaches:

- How the standard C library functions really behave (return values, edge cases, undefined behaviour).
- Pointer arithmetic, manual memory management (`malloc` / `free`) and leak-free code.
- Writing a `Makefile` and building a static library with `ar`.
- Respecting the 42 Norm and writing clean, reusable, modular code.

### Library overview

The library is split into three parts.

#### Part 1: Libc functions

Re-implementations of standard functions, with the same prototypes and behaviour as the originals, prefixed with `ft_`.

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

#### Part 2: Additional functions

Functions that are not in the libc, or that exist in a different form.

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring of a string, starting at a given index with a maximum length. |
| `ft_strjoin` | Allocates and returns a new string made of two strings concatenated. |
| `ft_strtrim` | Allocates and returns a copy of a string with a set of characters removed from both ends. |
| `ft_split` | Allocates and returns a NULL-terminated array of strings obtained by splitting a string on a delimiter character. |
| `ft_itoa` | Allocates and returns the string representation of an integer. |
| `ft_strmapi` | Applies a function to each character (with its index) of a string and returns a new string with the results. |
| `ft_striteri` | Applies a function to each character (with its index) of a string, in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

#### Part 3: Linked lists

This part defines the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees one node's content with a given function, then the node. |
| `ft_lstclear` | Deletes and frees a node and all its successors. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content, cleaning up on allocation failure. |

### Technical choices

- Written in C and compiled with `-Wall -Wextra -Werror`.
- The library is built with the `ar` command.
- Only authorised external functions are used (`malloc`, `free`, `write`).
- No global variables; helper functions are declared `static`.
- Every allocation is checked, and no memory is leaked.
- The prototype of each function matches the original libc (or the subject for the additional functions).
- Everything is declared in a single header, `libft.h`, protected against double inclusion.

## Instructions

### Requirements

- A C compiler (`cc`, `gcc` or `clang`)
- `make`
- `ar` (to create the static library)

### Compilation

Clone the repository and run `make` from its root:

```bash
git clone <repository_url> libft
cd libft
make
```

This produces the static library `libft.a` at the root of the repository.

| Rule | Effect |
|---|---|
| `make` / `make all` | Builds `libft.a`. |
| `make clean` | Removes the object files (`.o`). |
| `make fclean` | Removes the object files and `libft.a`. |
| `make re` | Runs `fclean`, then `all`. |

### Usage in your own project

1. Include the header in your source files:

   ```c
   #include "libft.h"
   ```

2. Compile your program and link it with the library:

   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

### Example

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello 42 world", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o example && ./example
```

## Resources

### References

- [`man 3` pages](https://man7.org/linux/man-pages/) for every re-implemented libc function (`man 3 strlcpy`, `man 3 memmove`, etc.)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language), Kernighan & Ritchie
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/)
- [cppreference.com: C reference](https://en.cppreference.com/w/c)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [42 Norm](https://github.com/42School/norminette) and the `norminette` tool

### Use of AI

AI was used as a **tutor**, not as a code generator. It was used for the following tasks:

- **Learning and practice:** generating exercises and small challenges to master key concepts (pointers, memory allocation, string handling, linked lists) and build a stronger foundation.
- **Quizzes:** generating quizzes about the concepts involved in the project, to test my understanding and spot gaps.
- **Finding resources:** gathering reliable references and learning material on the topics covered by the project.