// Process creation and termination
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent process started. PID = %d\n", getpid());

    pid = fork(); // Create child process

    if(pid < 0)
    {
        printf("Fork failed!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        // Child process
        printf("Child process running.\n");
        printf("Child PID = %d, Parent PID = %d\n", getpid(), getppid());

        printf("Child process terminating...\n");
        exit(0);
    }
    else
    {
        // Parent process
        wait(NULL);

        printf("Parent process resumed.\n");
        printf("Parent process terminating...\n");
    }

    return 0;
}