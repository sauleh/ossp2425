#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

// three threads writing in three different colors
// they should start counting from 1 ... 10
// total of 30 lines (in three differen colors)

#define COLOR1 "\033[1;35m"       // Bright yellow color
#define COLOR2 "\033[1;32m" // Bright green color
#define COLOR3 "\033[1;38m" // Bright green color
#define RESET "\033[0m"           // Reset color

#define sleeptime 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int i = 0;

void* print1(void* arg) {
    while (i<30) {
        pthread_mutex_lock(&mutex);
        printf(COLOR1);
        printf("AAAAA %d\n" , i);
        printf(RESET);
        i++;
        pthread_mutex_unlock(&mutex);

        usleep(sleeptime); 
    }
    return NULL;
}

void* print2(void* arg) {
    while (i<30) {
        pthread_mutex_lock(&mutex);
        printf(COLOR2);
        printf("BBBBB %d \n" , i);
        printf(RESET);
        i++;
        pthread_mutex_unlock(&mutex);
        usleep(sleeptime); 
    }
    return NULL;
}

void* print3(void* arg) {
    while (i<30) {
        pthread_mutex_lock(&mutex);
        printf(COLOR3);
        printf("CCCCC %d\n" , i);
        printf(RESET);
        i++;
        pthread_mutex_unlock(&mutex);
        usleep(sleeptime); 
    }
    return NULL;
}


int main() {
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, print1, NULL);
    pthread_create(&thread2, NULL, print2, NULL);
    pthread_create(&thread3, NULL, print3, NULL);

    printf("Hello from the main thread!\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Hello from the main thread!\n");
    return 0;
}
