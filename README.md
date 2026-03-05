# Get Next Line - @42Born2Code

## 💡 About

The **get_next_line** project is about creating a function that returns a line read from a file descriptor. Whether it's a file, the standard input, or even a network connection, this function allows you to read content line by line efficiently.

> "Reading a line from a fd is way more complex than it sounds when you have to manage memory and buffer sizes."

This project introduces the concept of **static variables** in C and deepens the understanding of **file descriptors** and **memory leaks**.

---

## 🛠️ The Function

The prototype of the function is:

```c
char *get_next_line(int fd);

```

### Key Features

* **Dynamic Buffering**: The function uses a `BUFFER_SIZE` defined at compilation.
* **Memory Efficiency**: It only reads what is necessary and preserves the "remainder" of the buffer for the next call using a static variable.
* **Multiple File Descriptors (Bonus)**: The bonus version can manage multiple file descriptors simultaneously without losing the reading thread of any of them.

---

## 📐 How it works

The logic relies on a loop that reads from the file descriptor until a newline character (`\n`) or the end of the file (`EOF`) is reached.

1. **Read**: Read `BUFFER_SIZE` bytes from the `fd`.
2. **Store**: Append the read content to our static "stash".
3. **Extract**: Look for `\n` in the stash. If found, slice the string, return the line, and keep the rest in the static variable.
4. **Repeat**: If no `\n` is found, read again.

---

## 🚀 Usage

### Compilation

You can compile your project with the following command (adjusting the buffer size as needed):

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

```

### Integration

To use it in your code:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

```
