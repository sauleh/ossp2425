#include <stdio.h>
#include <pthread.h>

// Thread function
void* thread_function(void* arg) {
    int* result = (int*)arg;  // Cast the argument to an int pointer
    *result = 42;  // Set the result to 42
    printf("Thread: Returning result = %d\n", *result);
    return NULL;  // No need to return anything since the caller provided memory
}

int main() {
    pthread_t thread;
    int thread_result;  // Memory for the result provided by the caller (on the stack)

    // Create the thread, passing the address of thread_result as the argument
    if (pthread_create(&thread, NULL, thread_function, &thread_result)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    // Print the received result
    printf("Main: Received result = %d\n", thread_result);

    return 0;
}