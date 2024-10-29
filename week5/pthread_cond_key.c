#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>

// Shared variables and synchronization primitives
int start_counting = 0;  // Flag to indicate if counting should start
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Function to disable buffered input for detecting key presses
void set_conio_mode() {
    struct termios new_settings;
    tcgetattr(0, &new_settings);
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new_settings);
}

// Waiting thread function for key input
void* wait_for_keypress(void* arg) {
    set_conio_mode();
    
    while (1) {
        printf("Press any key to start/stop counting...\n");
        getchar();  // Wait for a key press
        
        pthread_mutex_lock(&mutex);
        start_counting = !start_counting;  // Toggle the counting state
        pthread_cond_signal(&cond);        // Signal thread 2 to start/stop counting
        pthread_mutex_unlock(&mutex);

        usleep(100000);  // Sleep for a short time to avoid multiple triggers from a single key press
    }
    return NULL;
}

// Counting thread function
void* counting_thread(void* arg) {
    int counter = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        
        // Wait until start_counting is set to 1
        while (!start_counting) {
            pthread_cond_wait(&cond, &mutex);  // Wait for the condition signal
        }
        
        // Counting loop
        while (start_counting) {
            printf("Counter: %d\n", counter++);
            pthread_mutex_unlock(&mutex);
            sleep(1);  // Increment counter every second
            pthread_mutex_lock(&mutex);
        }
        
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t keypress_tid, counter_tid;

    // Create the threads
    pthread_create(&keypress_tid, NULL, wait_for_keypress, NULL);
    pthread_create(&counter_tid, NULL, counting_thread, NULL);

    // Wait for both threads to complete (in this case, they run indefinitely)
    pthread_join(keypress_tid, NULL);
    pthread_join(counter_tid, NULL);

    return 0;
}
