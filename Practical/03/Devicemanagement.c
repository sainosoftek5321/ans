#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    // Open terminal device
    fd = open("/dev/tty", O_RDWR);

    if(fd < 0)
    {
        perror("Device open failed");
        return 1;
    }

    // Ask user for input
    write(fd, "Enter some text: ", 17);

    // Read input from device
    int n = read(fd, buffer, sizeof(buffer));

    // Display entered text
    write(fd, "You entered: ", 13);
    write(fd, buffer, n);

    // Close device
    close(fd);

    return 0;
}