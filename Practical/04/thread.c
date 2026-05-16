// Thread creation and termination
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* thread_function(void* arg)
{
    printf("Thread is running...\n");
    printf("Thread ID: %lu\n", pthread_self());

    printf("Thread is terminating...\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;

    printf("Main process started.\n");

    // Create thread
    pthread_create(&thread, NULL, thread_function, NULL);

    // Wait for thread to finish
    pthread_join(thread, NULL);

    printf("Main process resumed after thread completion.\n");
    printf("Main process terminating...\n");

    return 0;
}