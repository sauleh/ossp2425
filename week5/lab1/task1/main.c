#include <stdio.h>
#include <stdlib.h>
#include "list.h"  // Include the standalone list.h

// Define a struct with list_head to represent a node in our list
struct my_data {
    int value;                // Example data to store
    struct list_head list;    // List head structure from list.h
};

int main() {
    LIST_HEAD(my_list); // Initialize the head of the list
    
    for (int i = 0; i < 5; i++) { // Add elements to the list
        struct my_data *new_node = malloc(sizeof(struct my_data));
        new_node->value = i;
        list_add(&new_node->list, &my_list);  // Add to the end of the list
    }

    printf("List contents:\n");
    struct list_head *pos;
    list_for_each(pos, &my_list) {
        struct my_data *node = list_entry(pos, struct my_data, list);
        printf("Value: %d\n", node->value);
    }
    
    struct list_head *q; // Remove elements and free memory
    list_for_each_safe(pos, q, &my_list) {
        struct my_data *node = list_entry(pos, struct my_data, list);
        list_del(pos);       // Remove the node from the list
        free(node);          // Free the memory
    }

    return 0;
}
