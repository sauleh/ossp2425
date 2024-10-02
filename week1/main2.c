#include<stdio.h>
int main()
{
    int nums[5] = {0xaa, 0xbb, 2, 4, 0xff};
    nums[2] = 5;
    int * pn = &(nums[2]);
    int x = pn[1];
    int* pn2 = &(nums[0]) + 3;
    char* pch = (char*) &(nums[0]);;
    pch += 12;
    char ch = 'A';
    char buf[10]="ABC";
    char buf2[4] ={'A', 'B', 'C', 0};

    // int a = 0x1feeaa00;
    // int b = 0xaaaaaaaa;
    // char ch = 'A';
    // long long int w = 0x0aaffaaffaaff;

    // printf("the size of int is: %d\n", sizeof(int));
    // printf("the size of char is: %d\n", sizeof(char));
    // printf("the size of float is: %d\n", sizeof(float));
    // printf("the size of long long int is: %d\n", sizeof(long long int));
    // printf("the size of double is: %d\n", sizeof(double));
    return 0;
}