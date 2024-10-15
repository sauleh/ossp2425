#include<windows.h>
#include<stdio.h>

typedef void (*fn_cb)(int);
typedef int (*fn_pair)(int,int);

void console(int n)
{
    printf("progress %d\n", n);
}

void sms_97123432432(int n)
{
    printf("sending sms to 97123432432, msg: %d\n", n);
}

void do_work(int max_work, fn_cb callback)
{
    for(int i=0; i<max_work; i++)
    {
        callback(i);
        Sleep(500);
    }
}

int* apply(int* a1, int*a2, int size, fn_pair fn)
{
    int* result = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++)
    {
        result[i] = fn(a1[i], a2[i]);
    }
    return result;
}

int add(int a, int b)
{
    return a+b;
}

int mul(int a, int b)
{
    return a*b;
}

int main()
{
    int nums1[] = {1,2,3,4,5};
    int nums2[] = {2,2,2,2,2};
    int* result = apply(nums1, nums2, 5, add);
    do_work(20, sms_97123432432);
    return 0;
}