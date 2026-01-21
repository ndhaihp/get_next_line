#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    buffer[100];  // Space for 10 characters + 1 null terminator
    ssize_t bytes_read;

    fd = open("file1.txt", O_RDONLY); // Open the file

    // Attempt to read 10 bytes from the file
    bytes_read = read(fd, buffer, 100);

    // IMPORTANT: read() does not add the null terminator for you!
    // We must manually add it using the number of bytes we actually read.
    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0'; 
        printf("We read: %s", buffer);
    }

    close(fd);
    return (0);
}
