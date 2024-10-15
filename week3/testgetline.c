#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[100];
    size_t n;
    int res;
    printf("Enter a string: ");
    fgets(buf, 100, stdin);
    // res = getline(&str, &n, stdin);
    // if (res != -1) {
    //    printf ("%s", str);
    // }
    // free(str);
    return 0;
}
