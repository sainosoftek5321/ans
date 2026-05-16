#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define MEM_SIZE 4096   // Typically one page size

int main()
{
    // Request memory mapping from kernel
    void *addr = mmap(NULL,
                      MEM_SIZE,
                      PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS,
                      -1,
                      0);

    if(addr == MAP_FAILED)
    {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    printf("Memory mapped at address: %p\n", addr);

    // Write data into mapped memory
    const char *message = "Hello, memory management system calls!";
    strncpy((char *)addr, message, MEM_SIZE - 1);

    // Read data from mapped memory
    printf("Content in mapped memory: %s\n", (char *)addr);

    // Unmap memory
    if(munmap(addr, MEM_SIZE) == -1)
    {
        perror("munmap failed");
        exit(EXIT_FAILURE);
    }

    printf("Memory unmapped successfully.\n");

    return 0;
}