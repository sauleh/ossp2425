#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

#define COLOR1 "\033[1;35m" 
#define COLOR2 "\033[1;32m" 
#define RESET "\033[0m"

int i = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#define sleeptime 1

void* print1(void* arg) {
    i=0;
    while (i<10) {
        pthread_mutex_lock(&mutex);
        printf(COLOR1);
        printf("PINK:%d\n" , i);
        usleep(sleeptime); 
        printf(RESET);
        i++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* print2(void* arg) {
    i=0;
    while (i<10) {
        pthread_mutex_lock(&mutex);
        printf(COLOR2);
        printf("GREEN:%d\n" , i);
        usleep(sleeptime); 
        printf(RESET);
        i++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, print1, NULL);
    pthread_create(&thread2, NULL, print2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
