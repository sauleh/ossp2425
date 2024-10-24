#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

#define COLOR1 "\033[1;35m" 
#define COLOR2 "\033[1;32m" 
#define RESET "\033[0m"


#define sleeptime 50

void* print1(void* arg) {
    int i=0;
    while (i<10) {
        printf("A:%d\n" , i);
        usleep(sleeptime); 
        i++;
    }
    return NULL;
}

void* print2(void* arg) {
    int i=0;
    while (i<10) {
        printf("B:%d\n" , i);
        usleep(sleeptime); 
        i++;
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
