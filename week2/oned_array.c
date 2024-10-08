#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Array elements:\n");
    // for (int i = 0; i < 5; i++) {
    //     printf("arr[%d] = %d\n", i, arr[i]);
    // }
    int * pn = arr;
    int count = 5;
    while(count--) // --count
    {
        printf("%d\n", *pn);
        pn++;
    }

    
    // Keep the program running so we can inspect memory in gdb
    printf("Press Enter to exit...\n");
    getchar();
    return 0;
}
