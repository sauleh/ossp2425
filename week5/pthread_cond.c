#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared variable and condition
int ready = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Waiting thread function
void* wait_thread(void* arg) {
    pthread_mutex_lock(&mutex);  // Lock the mutex before waiting
    printf("Waiting thread: Waiting for condition to be signaled...\n");

    while (!ready) {  // Check the condition in a loop
        pthread_cond_wait(&cond, &mutex);  // Wait for the condition signal
    }

    printf("Waiting thread: Condition met! Proceeding...\n");
    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

// Signaling thread function
void* signal_thread(void* arg) {
    sleep(1);  // Simulate some work before signaling
    pthread_mutex_lock(&mutex);  // Lock the mutex before modifying shared variable
    ready = 1;  // Set the condition to true
    printf("Signaling thread: Condition met, sending signal...\n");
    pthread_cond_signal(&cond);  // Signal the condition
    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

int main() {
    pthread_t wait_tid, signal_tid;

    // Create the waiting and signaling threads
    pthread_create(&wait_tid, NULL, wait_thread, NULL);
    pthread_create(&signal_tid, NULL, signal_thread, NULL);

    // Wait for both threads to complete
    pthread_join(wait_tid, NULL);
    pthread_join(signal_tid, NULL);

    return 0;
}
