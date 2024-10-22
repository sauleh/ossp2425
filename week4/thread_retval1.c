#include <stdio.h>
#include <pthread.h>

// Function to be executed by the thread
void* thread_function(void* arg) {
    int *result = (int *)malloc(sizeof(int)); // Allocate memory for the result
    if (result == NULL) {
        pthread_exit(NULL); // Exit thread if memory allocation fails
    }
    *result = 42; // Set the result to 42 for demonstration purposes
    printf("Thread: Returning result = %d\n", *result);
    return (void *)result; // Return the pointer to the allocated memory
}

int main() {
    pthread_t thread;
    int *thread_result = NULL;

    // Create the thread
    if (pthread_create(&thread, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the thread to finish and receive the return value
    if (pthread_join(thread, (void**)&thread_result)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    // Print the received result
    printf("Main: Received result = %d\n", *thread_result);

    // Free the allocated memory
    free(thread_result);

    return 0;
}
