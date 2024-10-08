#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("Two-dimensional array elements:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
    int* pn = &(arr[0][0]);
    int count = 6;
    while (count--)
    {
        printf("%d\n", *pn);
        pn++;
    }
    // Keep the program running so we can inspect memory in gdb
    printf("Press Enter to exit...\n");
    getchar();
    return 0;
}
