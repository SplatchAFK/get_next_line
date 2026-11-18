*This activity has been created as part of the 42 curriculum by romasant.*

# get_next_line

## Description

`get_next_line` reads a file descriptor and returns its content one line at a
time. Each call returns the next line, including the trailing `\n` when there
is one, and returns `NULL` when there is nothing left to read or when an error
occurs. It works with files, standard input and pipes, whatever the value of
`BUFFER_SIZE`.

The project teaches static variables, dynamic memory management (no leaks, no
invalid reads) and how to read data in chunks with `read`.

## Instructions

Files: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`.

Compile with the buffer size of your choice:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Without `-D BUFFER_SIZE`, the default value defined in the header is used.

Usage:

```c
int   fd = open("file.txt", O_RDONLY);
char  *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

Each returned line must be freed by the caller.

## Algorithm

The function keeps a `static` pointer, called the stock, which holds what has
been read from the file but not returned yet.

1. On each call, it reads `BUFFER_SIZE` bytes at a time with `read` and appends
   them to the stock (`ft_strjoin`), until the stock contains a `\n` or the end
   of the file is reached.
2. It then looks for the first `\n` in the stock. The line to return is a copy
   of the stock up to this `\n` included (or the whole stock if there is no
   `\n`), made with `ft_substr`.
3. The rest of the stock, what comes after the `\n`, is copied into a new
   string. The old stock is freed and replaced by this rest, ready for the next
   call.
4. When nothing is left in the stock and `read` returns 0, the function returns
   `NULL`. If `read` or a `malloc` fails, the memory is freed and the function
   returns `NULL`.

Keeping a stock is needed because one `read` can return several lines, or only
a part of a line. What is read after the `\n` must not be lost between two calls.

## Resources

- `man 2 read`, `man 3 malloc`, `man 3 free`
- The 42 `get_next_line` subject
- The "Le testeur des fous" tester, used to check the project (leaks, edge cases,
  `BUFFER_SIZE` values, failing `malloc`)

**Use of AI:** an AI assistant (Claude) was used as a tutor during the
project: to understand why some tests failed, to discuss how to split the code
into functions to respect the Norm, and to review fixes. I have read and
understood the final code. *(Modifie ce paragraphe pour qu'il reflète
exactement ce que tu as fait.)*
