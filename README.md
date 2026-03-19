# Get Next Line

*This project has been created as part of the 42 curriculum by dainguye.*

## Description

**get_next_line** is a C function that reads a file descriptor line by line. This is a fundamental 42 school project that teaches memory management, file I/O operations, and efficient buffer handling in C.

### Goal
The primary objective is to implement a function that:
- Reads successive lines from a file descriptor
- Returns one line at a time
- Manages memory efficiently
- Handles files of various sizes

The function must handle edge cases such as:
- Files with or without trailing newlines
- Files with single or multiple lines
- Empty files
- Large files with lines exceeding the buffer size

## Instructions

### Compilation

The project uses a configurable `BUFFER_SIZE` macro (default: 42 bytes). To compile with a custom buffer size:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 -c get_next_line.c get_next_line_utils.c
```

To compile with the default buffer size:

```bash
gcc -Wall -Wextra -Werror -c get_next_line.c get_next_line_utils.c
```

### Usage

```c
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

## Algorithm Explanation and Justification

### Overview
The implementation uses a **static buffer strategy** to efficiently read files line by line with a fixed, configurable buffer size.

### Algorithm Steps

1. **Initialization (`scoop_data`)**
   - Initialize or retrieve the static buffer for the given file descriptor
   - Read chunks of `BUFFER_SIZE` bytes from the file descriptor
   - Append each chunk to the growing buffer until a newline is found
   - Stop reading when a newline is encountered or EOF is reached

2. **Line Extraction (`extract_line`)**
   - Scan the buffer to find the first newline character
   - Extract a substring from the start of the buffer up to and including the newline
   - Return the extracted line

3. **Buffer Update (`extract_buffer`)**
   - Remove the extracted line from the buffer
   - Return the remaining data for the next `get_next_line` call
   - Free memory if no data remains

4. **Main Function (`get_next_line`)**
   - Combine the three operations above
   - Manage the static buffer across multiple calls
   - Return NULL when EOF is reached or an error occurs

### Why This Approach?

**Advantages:**
- **Efficiency**: Reads data in fixed-size chunks rather than character-by-character, reducing system calls
- **Simplicity**: Clear separation of concerns (scooping, extracting, buffering)
- **Flexibility**: `BUFFER_SIZE` can be adjusted for different use cases
- **Memory Safety**: Proper allocation and deallocation at each step
- **State Persistence**: Static buffer allows seamless reading across multiple function calls

**Memory Management:**
- The static buffer preserves remaining data between calls
- Extracted lines are returned to the caller (who must free them)
- All temporary allocations are freed immediately
- No memory leaks through careful use of error handling

## Features

- ✅ Reads files line by line efficiently
- ✅ Handles files with/without trailing newlines
- ✅ Configurable buffer size via `BUFFER_SIZE` macro
- ✅ Proper error handling (invalid file descriptors, read errors)
- ✅ Memory leak-free implementation

## Technical Choices

### Static Buffer
Using a static buffer allows the function to maintain state between calls without requiring external context or structures. This is simpler than passing a context object but requires careful management for multiple file descriptors.

### Chunked Reading
Instead of reading the entire file at once (which could exceed available memory) or reading one character at a time (which causes excessive system calls), the algorithm reads in chunks of `BUFFER_SIZE` bytes. This balances memory usage and performance.

### String Manipulation Functions
Helper functions (`ft_strchr`, `ft_strjoin`, `ft_substr`, `ft_strdup`, `ft_strlen`) are implemented from scratch to avoid external dependencies and ensure complete control over memory management.

## Resources

### Documentation
- [Input-Output System Calls in C - read() function](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/#4-read) - GeeksforGeeks comprehensive guide to read() function

- [Static variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/) - GeeksforGeeks guide to understanding persistent state and static variables

### AI Usage

AI assistance was used for the following tasks:

1. **Code Review and Optimization**: Generated suggestions for memory efficiency and edge case handling
2. **Documentation**: Helped structure and refine this README with clear explanations of the algorithm
3. **Testing Assistance**: Provided insights on test cases and boundary conditions to verify correctness

AI did not write the core implementation—the algorithm and code logic were developed independently following 42 school guidelines.

## Author

- **dainguye** - 42 Prague

---

*Last Updated: January 2026*
