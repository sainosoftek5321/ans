#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    // Main process information
    printf("Main process (before fork): PID = %d, PPID = %d\n",
           getpid(), getppid());

    // Create child process
    pid = fork();

    if(pid < 0)
    {
        // Fork failed
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if(pid == 0)
    {
        // Child process
        printf("Child process: PID = %d, PPID = %d\n",
               getpid(), getppid());

        printf("Child process is running...\n");

        // Child process exits
        exit(0);
    }
    else
    {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n",
               getpid(), pid);

        printf("Parent process is waiting for the child to complete...\n");

        // Parent waits for child process
        wait(NULL);

        printf("Parent process detected child completion.\n");
        printf("Parent process is exiting.\n");
    }

    return 0;
}