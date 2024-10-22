#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

// ANSI escape codes for text colors
#define YELLOW "\033[1;35m"       // Bright yellow color
#define BRIGHT_GREEN "\033[1;32m" // Bright green color
#define RESET "\033[0m"           // Reset color

// Function executed by the first thread (prints in yellow)
void* print_yellow(void* arg) {
    usleep(500000); // Sleep for 500 ms
    for (int i = 0; i < 5; i++) {
        printf(YELLOW "Hello from the Yellow thread!\n" RESET);
        usleep(1000000); // Sleep for 500 ms
    }
    return NULL;
}

// Function executed by the second thread (prints in bright green)
void* print_bright_green(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf(BRIGHT_GREEN "Hello from the Bright Green thread!\n" RESET);
        usleep(1000000); // Sleep for 500 ms
    }
    return NULL;
}

int main1()
{
    print_bright_green(NULL);
    print_yellow(NULL);
    return 0;
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    pthread_create(&thread1, NULL, print_yellow, NULL);

    // Create the second thread
    pthread_create(&thread2, NULL, print_bright_green, NULL);

    printf("Hello from the main thread!\n");

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Hello from the main thread!\n");
    return 0;
}
