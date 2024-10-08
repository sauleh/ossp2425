#include<stdio.h>
int main()
{
    int a = 0xaabbaabb;
    int w = 0xccccffff;
    double x[4] = {0xaa, 0xbb, 0xff, 0xdd};
    printf("%d\n", sizeof(x));



    return 0;
}