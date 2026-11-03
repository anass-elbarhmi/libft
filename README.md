*This project has been created as part of the 42 curriculum by ael-barh.*

# Libft

> Your first own C library: re-build the standard functions you use every day, understand how they work under the hood, and create the toolbox you will reuse in every future 42 project.

---

## Table of Contents

1. [Description](#description)
2. [What You Will Learn](#what-you-will-learn)
3. [Core Concepts Explained Simply](#core-concepts-explained-simply)
4. [Library Overview](#library-overview)
   - [Part 1: Libc functions](#part-1-libc-functions)
   - [Part 2: Additional functions](#part-2-additional-functions)
   - [Part 3: Linked lists](#part-3-linked-lists)
5. [Technical Choices](#technical-choices)
6. [Instructions](#instructions)
7. [Project Structure](#project-structure)
8. [Testing Your Library](#testing-your-library)
9. [Common Pitfalls](#common-pitfalls)
10. [Suggested Learning Path](#suggested-learning-path)
11. [Resources](#resources)
12. [Use of AI](#use-of-ai)

---

## Description

**Libft** is the first project of the 42 common core. The goal is to build, from scratch, your own C static library (`libft.a`) that re-implements a set of standard C library functions, adds a few useful utility functions, and provides basic linked-list manipulation. This library is meant to be reused and extended in all later 42 projects.

**Why rebuild functions that already exist?**
Because using a function and understanding a function are two different things. By writing `strlen`, `memmove` or `atoi` yourself, you discover what happens in memory, what the edge cases are, and why the original functions behave the way they do. Every project after Libft (`ft_printf`, `get_next_line`, `push_swap`, `minishell`, ...) will rely on the tools you build here.

The project teaches:

- How the standard C library functions really behave (return values, edge cases, undefined behaviour).
- Pointer arithmetic, manual memory management (`malloc` / `free`) and leak-free code.
- Writing a `Makefile` and building a static library with `ar`.
- Respecting the 42 Norm and writing clean, reusable, modular code.

---

## What You Will Learn

Each skill below is practised directly by a group of functions in the project.

| Skill | What it means | Where you practise it |
|---|---|---|
| **Pointers and pointer arithmetic** | Moving through memory byte by byte, understanding `*p`, `p + 1`, `&x`, and pointer types. | `ft_strlen`, `ft_strchr`, `ft_memchr`, `ft_memcpy` |
| **Strings in C** | A string is just an array of `char` ending with `'\0'`. Forgetting the terminator is the #1 source of bugs. | All `ft_str*` functions |
| **Raw memory manipulation** | Working with bytes without caring about their meaning (`void *`, casting to `unsigned char *`). | `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memcmp` |
| **Overlapping memory** | Why copying memory can corrupt data when source and destination overlap, and how to avoid it. | `ft_memmove` vs `ft_memcpy` |
| **Dynamic memory allocation** | Asking the system for memory with `malloc`, giving it back with `free`, and handling failure. | `ft_strdup`, `ft_calloc`, `ft_substr`, `ft_split`, `ft_itoa` |
| **Memory leaks and ownership** | Knowing who is responsible for freeing what, and freeing everything on error paths. | `ft_split`, `ft_lstmap`, `ft_lstclear` |
| **Defensive programming** | Checking every `malloc`, handling `NULL` inputs, empty strings, zero sizes and overflows. | The whole library |
| **Integer overflow and limits** | What happens at `INT_MIN`, `INT_MAX`, or with `size_t` multiplication. | `ft_atoi`, `ft_itoa`, `ft_putnbr_fd`, `ft_calloc` |
| **Function pointers** | Passing a function as an argument to apply it to data. | `ft_strmapi`, `ft_striteri`, `ft_lstiter`, `ft_lstmap`, `ft_lstdelone` |
| **Data structures** | Building a singly linked list with nodes allocated on the heap. | The `ft_lst*` functions |
| **File descriptors and system calls** | Writing to the screen or a file with `write`. | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| **Build systems** | Writing a `Makefile` with proper rules, and creating a static library with `ar`. | `Makefile`, `libft.a` |
| **Header files** | Declaring prototypes, using include guards, organising a reusable API. | `libft.h` |
| **Code style (the Norm)** | Writing short, readable functions with strict formatting rules. | All files |
| **Reading documentation** | Using `man` pages to find the exact behaviour of a function. | Every libc re-implementation |

---

## Core Concepts Explained Simply

If you are new to C, read this section first. It explains the ideas that the rest of the project depends on.

### 1. Memory: stack vs heap

- **Stack**: automatic memory for local variables. It is freed automatically when the function returns.
- **Heap**: memory you request manually with `malloc`. It stays alive until you call `free`. If you forget to free it, you have a **memory leak**.

```c
char *str = malloc(5);   /* ask for 5 bytes on the heap */
if (!str)                /* malloc can fail and return NULL */
	return (NULL);
/* ... use str ... */
free(str);               /* give the memory back */
```

### 2. Strings

A C string is an array of characters followed by a special byte `'\0'` (the *null terminator*). The string `"42"` takes **3** bytes: `'4'`, `'2'`, `'\0'`. Every string function relies on this terminator to know where the string ends, so when you allocate space, always count `+ 1` for it.

### 3. Pointers

A pointer stores the **address** of a value. Pointer arithmetic moves by the size of the pointed type: `p + 1` on a `char *` moves 1 byte, on an `int *` it moves 4 bytes (typically).

### 4. `void *` and generic memory

Functions like `memcpy` work on any type of data, so they use `void *`. You cannot dereference a `void *`, so inside the function you cast it to `unsigned char *` to read and write byte by byte.

### 5. `size_t`

An unsigned integer type used for sizes and lengths. Be careful: subtracting from an unsigned value below zero does not give a negative number, it wraps around to a huge value.

### 6. Undefined behaviour

When the C standard does not define what happens (for example, passing `NULL` to `strlen`, or overlapping buffers in `memcpy`), the program may crash, work by accident, or silently corrupt data. Learning to recognise these situations is a major goal of this project.

### 7. Static library

A `.a` file is an archive of compiled object files (`.o`). When you link it into a program, the linker copies only the functions you use. You create it with `ar`.

---

## Library Overview

The library is split into three parts.

### Part 1: Libc functions

Re-implementations of standard functions, with the same prototypes and behaviour as the originals, prefixed with `ft_`.

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

#### Detailed guide: character functions

| Function | What it does | What you learn |
|---|---|---|
| `ft_isalpha` | Returns non-zero if the character is a letter (`A-Z`, `a-z`). | Working with ASCII ranges and character comparisons. |
| `ft_isdigit` | Returns non-zero if the character is a digit (`0-9`). | Same idea; the base of number parsing. |
| `ft_isalnum` | Returns non-zero if the character is a letter or a digit. | Reusing functions you already wrote. |
| `ft_isascii` | Returns non-zero if the value is in the ASCII range (`0-127`). | Understanding the ASCII table. |
| `ft_isprint` | Returns non-zero if the character is printable (`32-126`). | Difference between printable and control characters. |
| `ft_toupper` | Converts a lowercase letter to uppercase, leaves anything else unchanged. | The offset of `32` between `'a'` and `'A'`. |
| `ft_tolower` | Converts an uppercase letter to lowercase, leaves anything else unchanged. | Same, in reverse. |

#### Detailed guide: string functions

| Function | What it does | What you learn |
|---|---|---|
| `ft_strlen` | Returns the number of characters before the `'\0'`. | Walking through a string with a pointer or an index. |
| `ft_strlcpy` | Copies up to `size - 1` characters and always null-terminates (if `size > 0`). Returns the length of the **source**. | Safe copying, truncation detection, why the return value is the source length. |
| `ft_strlcat` | Appends a string to another without exceeding `size` total bytes. Returns the length it **tried** to create. | Safe concatenation and careful size arithmetic. |
| `ft_strchr` | Finds the **first** occurrence of a character in a string. Can also find the `'\0'`. | Returning a pointer inside the original string. |
| `ft_strrchr` | Finds the **last** occurrence of a character in a string. | Scanning in the right direction; handling `'\0'`. |
| `ft_strncmp` | Compares at most `n` characters of two strings. Returns the difference of the first different bytes. | Comparing as `unsigned char`; early stop on `'\0'`. |
| `ft_strnstr` | Finds a substring (needle) inside a string (haystack), looking at no more than `len` characters. | Nested loops, bounds, empty needle edge case. |
| `ft_strdup` | Allocates a new copy of a string. | First real use of `malloc`; who frees the result. |

#### Detailed guide: memory functions

| Function | What it does | What you learn |
|---|---|---|
| `ft_memset` | Fills `n` bytes with a given byte value. | Treating memory as raw bytes; why the value is converted to `unsigned char`. |
| `ft_bzero` | Sets `n` bytes to zero. | A special case of `memset`. |
| `ft_memcpy` | Copies `n` bytes from source to destination. Buffers must **not** overlap. | Casting `void *`; undefined behaviour with overlap. |
| `ft_memmove` | Copies `n` bytes and **handles overlap** correctly. | Copying forward vs backward depending on the addresses. |
| `ft_memchr` | Finds the first occurrence of a byte in `n` bytes of memory. | Searching raw memory (does not stop at `'\0'`). |
| `ft_memcmp` | Compares `n` bytes of two memory areas. | Byte comparison, returning a difference. |
| `ft_calloc` | Allocates memory for `nmemb` elements of `size` bytes and sets everything to zero. | `malloc` + `bzero`, plus overflow protection on `nmemb * size`. |

#### Detailed guide: conversion

| Function | What it does | What you learn |
|---|---|---|
| `ft_atoi` | Converts the beginning of a string to an `int`. Skips whitespace, handles one optional sign `+` / `-`, then reads digits. | Parsing text, state handling (whitespace, sign, digits), building a number digit by digit (`n = n * 10 + digit`). |

---

### Part 2: Additional functions

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

#### Detailed guide: additional functions

| Function | What you need to think about | What you learn |
|---|---|---|
| `ft_substr` | What if `start` is beyond the end of the string? What if `len` is longer than what remains? Return an empty string, not `NULL`, when nothing remains. | Bounds checking and calculating the exact size to allocate. |
| `ft_strjoin` | Allocate `len(s1) + len(s2) + 1`. Never modify the inputs. | Building a new string from two sources. |
| `ft_strtrim` | Find the first and last characters **not** in the set, then copy what lies between. Handle a string made only of characters to trim. | Two-ended scanning and reusing `ft_substr`. |
| `ft_split` | Count the words first, allocate the array (`words + 1`), allocate each word, and set the last pointer to `NULL`. If any allocation fails, free everything allocated so far. Consecutive delimiters must not create empty words. | The most demanding exercise of the project: nested allocation, cleanup on failure, and splitting into small helper functions. |
| `ft_itoa` | Handle `0`, negative numbers and especially `INT_MIN` (`-2147483648`), which cannot be negated in an `int`. Count the digits to know the size. | Integer limits and converting numbers to text. |
| `ft_strmapi` | Your function receives the index and the character, and returns a new character. The result is a **new** string. | Function pointers as arguments. |
| `ft_striteri` | Same idea but the string is modified **in place** (the function receives a pointer to the character). | Difference between returning a new value and modifying the original. |
| `ft_putchar_fd` | One call to `write`. | The `write` system call and file descriptors (`0` stdin, `1` stdout, `2` stderr). |
| `ft_putstr_fd` | Write the whole string. Handle `NULL` safely. | Combining `ft_strlen` with `write`. |
| `ft_putendl_fd` | A string followed by `'\n'`. | Reusing previous functions. |
| `ft_putnbr_fd` | Print a number digit by digit, including negatives and `INT_MIN`, without using `printf`. | Recursion (or loops) and edge cases. |

---

### Part 3: Linked lists

This part defines the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

A **linked list** is a chain of nodes. Each node stores some data (`content`, a generic `void *`) and a pointer to the next node (`next`). The last node points to `NULL`.

```
 head
  |
  v
+---------+---+     +---------+---+     +---------+------+
| content | * | --> | content | * | --> | content | NULL |
+---------+---+     +---------+---+     +---------+------+
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

#### Detailed guide: linked list functions

| Function | Key idea | What you learn |
|---|---|---|
| `ft_lstnew` | Allocate one node, store the content, set `next` to `NULL`. | Allocating a struct on the heap. |
| `ft_lstadd_front` | The new node points to the old head, and becomes the new head. The head is passed as `t_list **` so the caller's pointer can be updated. | Why a **pointer to a pointer** is needed to modify a pointer. |
| `ft_lstsize` | Walk the list and count. | Traversing a list. |
| `ft_lstlast` | Walk until `next == NULL`. | Stopping at the last node, not past it. |
| `ft_lstadd_back` | If the list is empty, the new node becomes the head; otherwise attach it after the last node. | Handling the empty-list special case. |
| `ft_lstdelone` | Call the delete function on `content`, then free the node itself. | Ownership: the node owns its content. |
| `ft_lstclear` | Save `next` **before** freeing the current node, free every node, then set the head to `NULL`. | Avoiding use-after-free. |
| `ft_lstiter` | Apply a function to every node's content. | Function pointers on data structures. |
| `ft_lstmap` | Build a brand new list from the results. If any allocation fails, clear the partial list and the created contents, then return `NULL`. | Complete error handling and leak-free cleanup. |

---

## Technical Choices

- Written in C and compiled with `-Wall -Wextra -Werror`.
- The library is built with the `ar` command.
- Only authorised external functions are used (`malloc`, `free`, `write`).
- No global variables; helper functions are declared `static`.
- Every allocation is checked, and no memory is leaked.
- The prototype of each function matches the original libc (or the subject for the additional functions).
- Everything is declared in a single header, `libft.h`, protected against double inclusion.

---

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

**What happens when you run `make`?**

1. Each `.c` file is compiled into a `.o` object file with `cc -Wall -Wextra -Werror -c`.
2. All `.o` files are packed into one archive with `ar rcs libft.a *.o`.
3. Running `make` again does nothing if no file changed (the Makefile must not relink needlessly).

### Usage in your own project

1. Include the header in your source files:

   ```c
   #include "libft.h"
   ```

2. Compile your program and link it with the library:

   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

   - `-L.` tells the compiler to look for libraries in the current directory.
   - `-lft` links the library named `libft.a`.

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

Expected output:

```
hello
42
world
```

---

## Project Structure

```
libft/
├── Makefile
├── libft.h          # all prototypes + t_list definition
├── ft_isalpha.c     # one function per file
├── ft_strlen.c
├── ft_split.c
├── ft_lstnew.c
├── ...
└── libft.a          # generated by make
```

Each function lives in its own `.c` file named after the function. This keeps the code modular and lets the linker include only what a program needs.

---

## Testing Your Library

You are responsible for testing your own code. Good habits:

1. **Compare with the original.** For every libc function, write a small `main` that calls both `ft_xxx` and `xxx` with the same inputs and compares the results.
2. **Test the edges.** Empty strings, a size of `0`, a size larger than the string, `INT_MIN`, `INT_MAX`, negative numbers, overlapping buffers.
3. **Check for leaks.** Use `valgrind --leak-check=full ./a.out` on Linux, or `leaks` on macOS.
4. **Use sanitizers.** Compile with `-fsanitize=address -g` to catch out-of-bounds access and use-after-free.
5. **Run the Norm.** Use `norminette` on all your files before submitting.
6. **Try community testers** only after writing your own tests, so you understand each failing case.

---

## Common Pitfalls

| Pitfall | Why it matters |
|---|---|
| Forgetting the `'\0'` when allocating or copying | Causes unterminated strings and unpredictable output. |
| Not checking the return value of `malloc` | A `NULL` dereference crashes the program. |
| Using `memcpy` logic in `memmove` | Breaks when source and destination overlap. |
| Comparing characters as `char` instead of `unsigned char` | Gives wrong results for values above 127. |
| Negating `INT_MIN` | Overflows an `int`; use a `long` or handle it separately. |
| Not freeing already-allocated memory when a later allocation fails | A classic leak, especially in `ft_split` and `ft_lstmap`. |
| Freeing a node before saving its `next` pointer | Use-after-free in `ft_lstclear`. |
| Passing `t_list *` instead of `t_list **` to functions that modify the head | The caller's list is not updated. |
| Multiplying `nmemb * size` without overflow check in `ft_calloc` | Allocates less memory than expected. |

---

## Suggested Learning Path

Follow this order to build knowledge step by step:

1. **Warm-up:** character functions (`ft_isalpha` ... `ft_tolower`) and `ft_strlen`.
2. **Strings:** `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_atoi`.
3. **Raw memory:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.
4. **First allocations:** `ft_calloc`, `ft_strdup`.
5. **Allocation-based utilities:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_itoa`.
6. **Function pointers:** `ft_strmapi`, `ft_striteri`.
7. **Output:** the `ft_put*_fd` functions.
8. **The hard one:** `ft_split` (plan it on paper first).
9. **Linked lists:** `ft_lstnew` through `ft_lstmap`.
10. **Build system:** finalise your `Makefile` and verify `make`, `make clean`, `make fclean`, `make re` all behave correctly.

---

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