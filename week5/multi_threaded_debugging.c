#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared variable
int shared_var = 0;
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to increment the shared variable
void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_var++;
    }
    return NULL;
}

// Thread function to decrement the shared variable
void* decrement(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_var--;
    }
    return NULL;
}

int main() {
    pthread_t inc_thread, dec_thread;

    // Create the increment and decrement threads
    pthread_create(&inc_thread, NULL, increment, NULL);
    pthread_create(&dec_thread, NULL, decrement, NULL);

    // Wait for both threads to complete
    pthread_join(inc_thread, NULL);
    pthread_join(dec_thread, NULL);

    // Print the final value of the shared variable
    printf("Final value of shared_var: %d\n", shared_var);

    return 0;
}
