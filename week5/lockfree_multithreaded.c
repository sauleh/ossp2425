#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <time.h>

#define ITERATIONS 10000000

// Shared variables
atomic_int atomic_counter = 0;
int mutex_counter = 0;
int unsafe_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function using atomic fetch_add
void* atomic_add(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        atomic_fetch_add(&atomic_counter, 1);
    }
    return NULL;
}

// Function using mutex
void* mutex_add(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        mutex_counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Function without any safety
void* unsafe_add(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        unsafe_counter++;
    }
    return NULL;
}

// Function to measure elapsed time
double measure_time(void* (*func)(void*)) {
    pthread_t thread1, thread2;
    clock_t start = clock();

    pthread_create(&thread1, NULL, func, NULL);
    pthread_create(&thread2, NULL, func, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    // Measure time for atomic fetch_add
    double atomic_time = measure_time(atomic_add);
    printf("Time with atomic_fetch_add: %f seconds\n", atomic_time);
    printf("Atomic Counter: %d\n\n", atomic_counter);

    // Measure time for mutex lock
    double mutex_time = measure_time(mutex_add);
    printf("Time with mutex: %f seconds\n", mutex_time);
    printf("Mutex Counter: %d\n\n", mutex_counter);

    // Measure time without any safety
    double unsafe_time = measure_time(unsafe_add);
    printf("Time without safety: %f seconds\n", unsafe_time);
    printf("Unsafe Counter: %d\n\n", unsafe_counter);

    return 0;
}
