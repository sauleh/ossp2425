#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    
    // Print the contents of argv
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] (address: %p) = %s\n", i, (void*)argv[i], argv[i]);
    }

    // Print the individual characters of each argument
    for (int i = 0; i < argc; i++) {
        printf("Characters in argv[%d]:\n", i);
        for (int j = 0; argv[i][j] != '\0'; j++) {
            printf("argv[%d][%d] (address: %p) = %c\n", i, j, (void*)&argv[i][j], argv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
