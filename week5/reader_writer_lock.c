#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2
#define NUM_ITERATIONS 10

// Shared variable
int shared_data = 0;

// Reader-writer lock
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

// Reader function
void* reader(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_rwlock_rdlock(&rwlock);  // Acquire read lock
        printf("Reader %d: read shared_data = %d\n", id, shared_data);
        pthread_rwlock_unlock(&rwlock);  // Release read lock
        usleep(100000);  // Sleep for 100 ms
    }
    return NULL;
}

// Writer function
void* writer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_rwlock_wrlock(&rwlock);  // Acquire write lock
        shared_data++;  // Modify shared data
        printf("Writer %d: wrote shared_data = %d\n", id, shared_data);
        pthread_rwlock_unlock(&rwlock);  // Release write lock
        usleep(300000);  // Sleep for 300 ms
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int ids[NUM_READERS > NUM_WRITERS ? NUM_READERS : NUM_WRITERS];

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy the reader-writer lock
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
