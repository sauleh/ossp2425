#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

// ANSI escape codes for text colors
#define YELLOW "\033[1;35m"       // Bright yellow color
#define BRIGHT_GREEN "\033[1;32m" // Bright green color
#define RESET "\033[0m"           // Reset color

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function executed by the first thread (prints in yellow)
void* print_yellow(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        printf(YELLOW);
        printf("Yellow\n");
        printf(RESET);
        pthread_mutex_unlock(&mutex);
        usleep(10); // Sleep for 500 ms
    }
    return NULL;
}

// Function executed by the second thread (prints in bright green)
void* print_bright_green(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        printf(BRIGHT_GREEN);
        printf("Green\n");
        printf(RESET);
        pthread_mutex_unlock(&mutex);
        usleep(10); // Sleep for 500 ms
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    pthread_create(&thread1, NULL, print_yellow, NULL);

    // Create the second thread
    pthread_create(&thread2, NULL, print_bright_green, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Hello from the main thread!\n");
    return 0;
}
