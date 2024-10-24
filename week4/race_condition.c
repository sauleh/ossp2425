#include <stdio.h>
#include <string.h>
#include <pthread.h>

int n = 0;

void t1()
{
	for (int i = 0; i < 100000; i++) {
		n++;
	}
}

void t2()
{
	for (int i = 0; i < 100000; i++) {
		n--;
	}
}


int main(void)
{
	pthread_t thread1,  thread2;

	pthread_create(&thread1,
		NULL,
		(void *)t1,
		NULL);

	pthread_create(&thread2,
		NULL,
		(void *)t2,
		NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("100,000 - 100,000 should be zero but it is  %d\n", n);

	return 0;
}