#include <stdio.h>

int sum(int ** ja, int size, int* sizes)
{
    int sum=0;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<sizes[i]; j++)
        {
            sum += ja[i][j];
        }
    }
    return sum;
        // printf("%x", ja[i]);
}

int main() {
    // Simulate a jagged array using an array of pointers
    int row0[3] = {1, 2, 3};      // First row with 3 elements
    int row1[2] = {4, 5};         // Second row with 2 elements

    int *arr[2];                 // Array of pointers to int
    arr[0] = row0;               // First row points to row0
    arr[1] = row1;               // Second row points to row1

    int sizes[2] = {3, 2};
    int s = sum(arr, 2, sizes);
    printf("%d\n", s);

    // Print the elements
    printf("Jagged array elements:\n");
    for (int i = 0; i < 3; i++) {
        printf("arr[0][%d] = %d\n", i, arr[0][i]);
    }
    for (int i = 0; i < 2; i++) {
        printf("arr[1][%d] = %d\n", i, arr[1][i]);
    }

    // Keep the program running so we can inspect memory in gdb
    printf("Press Enter to exit...\n");
    getchar();

    return 0;
}
