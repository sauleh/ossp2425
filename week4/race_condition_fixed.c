#include <stdio.h>
#include <string.h>
#include <pthread.h>

volatile int n = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void do_one_thing()
{
	for (int i = 0; i < 100000; i++) {
		pthread_mutex_lock(&mutex1);
		n--;
		pthread_mutex_unlock(&mutex1);
	}
}

void do_another_thing()
{
	for (int i = 0; i < 100000; i++) {
		pthread_mutex_lock(&mutex1);
		n++;
		pthread_mutex_unlock(&mutex1);
	}
}


int main(void)
{
	pthread_t thread1,  thread2;

	pthread_create(&thread1,
		NULL,
		(void *)do_one_thing,
		NULL);

	pthread_create(&thread2,
		NULL,
		(void *)do_another_thing,
		NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("100,000 - 100,000 should be zero and it is %d\n", n);

	return 0;
}