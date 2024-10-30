#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "list.h"  // Include the standalone list.h

// Define a struct with list_head to represent a node in our list
struct my_data {
    int value;                // Example data to store
    struct list_head list;    // List head structure from list.h
};

LIST_HEAD(my_list); // Initialize the head of the list

void* fn_add(void* arg)
{
    for (int i = 0; i < 500000; i++) { // Add elements to the list
        struct my_data *new_node = malloc(sizeof(struct my_data));
        new_node->value = i;
        list_add(&new_node->list, &my_list);  // Add to the end of the list
    }
}

int main() {
    pthread_t adder_thread1, adder_thread2;
    pthread_create(&adder_thread1, NULL, fn_add, NULL);
    pthread_create(&adder_thread2, NULL, fn_add, NULL);

    // Wait for the threads to finish (they won’t in this example, but for completeness)
    pthread_join(adder_thread1, NULL);
    pthread_join(adder_thread2, NULL);

    int count = 0;
    struct list_head *pos;    
    struct list_head *q; // Remove elements and free memory
    list_for_each_safe(pos, q, &my_list) {
        struct my_data *node = list_entry(pos, struct my_data, list);
        list_del(pos);       // Remove the node from the list
        free(node);          // Free the memory
        count++;
    }
    printf("\ntotal added: %d\n", count);

    return 0;
}
