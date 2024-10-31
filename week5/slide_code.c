#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int  count = 0;
#define COUNT_DONE  150
#define COUNT_HALT1  10
#define COUNT_HALT2  90

pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

void *functionCount1() {
   for(;;) {
      pthread_mutex_lock(&condition_mutex);
      while(count >= COUNT_HALT1 && count <= COUNT_HALT2) {
         pthread_cond_wait(&condition_cond, &condition_mutex);
      }
      pthread_mutex_unlock(&condition_mutex);
      pthread_mutex_lock(&count_mutex);
      count++;
      printf("Counter value functionCount1: %d\n", count);
      pthread_mutex_unlock(&count_mutex);
      if(count >= COUNT_DONE) return(NULL);
    }
}

void *functionCount2() {
    for(;;) {
       pthread_mutex_lock(&condition_mutex);
       if(count > COUNT_HALT2 ){
          pthread_cond_signal(&condition_cond);
       }
       pthread_mutex_unlock(&condition_mutex);
       pthread_mutex_lock(&count_mutex);
       count++;
       printf("Counter value functionCount2: %d\n",count);
       pthread_mutex_unlock(&count_mutex);
       if(count >= COUNT_DONE) return(NULL);
    }
}

int main()
{
    pthread_t fn1_thread, fn2_thread;
    pthread_create(&fn1_thread, NULL, functionCount1, NULL);
    pthread_create(&fn2_thread, NULL, functionCount2, NULL);
    pthread_join(fn1_thread, NULL);
    pthread_join(fn2_thread, NULL);
    return 0;
}