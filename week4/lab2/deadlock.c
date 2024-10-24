#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define COLOR1 "\033[1;35m" 
#define COLOR2 "\033[1;32m" 
#define COLOR3 "\033[1;38m" 
#define RESET "\033[0m"     

volatile int n = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void t1()
{
    while(1)
    {
        printf(COLOR1 "t1: waiting for mutex1\n");
		pthread_mutex_lock(&mutex1);
        printf(COLOR1 "t1: waiting for mutex2\n");
		pthread_mutex_lock(&mutex2);
        usleep(100);        
        printf(COLOR1 "t1: releasing mutex2\n");
		pthread_mutex_unlock(&mutex1);
        printf(COLOR1 "t1: releasing mutex1\n");
		pthread_mutex_unlock(&mutex2);
	}
}

void t2()
{
    while(1)
    {
        printf(COLOR2 "t2: waiting for mutex1\n");
		pthread_mutex_lock(&mutex2);
        printf(COLOR2 "t2: waiting for mutex2\n");
		pthread_mutex_lock(&mutex1);
        usleep(100);        
        printf(COLOR2 "t2: releasing mutex2\n");
		pthread_mutex_unlock(&mutex2);
        printf(COLOR2 "t2: releasing mutex1\n");
		pthread_mutex_unlock(&mutex1);
	}
}


int main(void)
{
	pthread_t thread1,  thread2;

	pthread_create(&thread1,NULL, (void *)t1, NULL);

	pthread_create(&thread2, NULL, (void *)t2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}