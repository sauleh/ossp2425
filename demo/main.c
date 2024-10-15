#include<pthread.h>
#include<stdio.h>



void* myThreadFunc(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, myThreadFunc, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    printf("Hello from main!\n");
    return 0;
}
