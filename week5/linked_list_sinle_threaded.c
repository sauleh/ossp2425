#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define TCOUNT 100000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;  // Head of the linked list

// Function to add a node to the linked list
void add_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Function to remove a node from the linked list
void remove_node() {
    if (head == NULL) return;  // List is empty

    Node* temp = head;
    head = head->next;
    free(temp);
}

// Thread function to continuously add nodes to the list
void* adder_thread(void* arg) {
    int count = 0;
    while (count < TCOUNT*4) {
        add_node(count);
        // printf("\rAdded node with data: %d", count);
        count++;
    }
    return NULL;
}

int main() {
    pthread_t adder1;

    struct timespec start, end;
    double elapsed;

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &start);


    // Create two threads: one for adding and one for removing nodes
    pthread_create(&adder1, NULL, adder_thread, NULL);

    // Wait for the threads to finish (they won’t in this example, but for completeness)
    pthread_join(adder1, NULL);

    int count = 0;
    Node* current = head;
    while (current)
    {
        count++;
        current = current->next;
    }
    printf("\ncount: %d but should be %d\n", count, TCOUNT * 4);

    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate elapsed time in seconds
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Elapsed time: %f seconds\n", elapsed);    

    getchar();

    return 0;
}
