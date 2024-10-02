#include<stdio.h>
int main()
{
    int a;
    int b;
    int c;
    int buf[10];
    printf("%d, %d, %d\n", a, b, c);
    buf[5] = 12;
    printf("%d\n", buf[5]);
    int* ptr = &(buf[0]);
    ptr += 5;
    printf("%d\n", *ptr);
    return 0;
}