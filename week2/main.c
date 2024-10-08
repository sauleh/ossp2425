#include<stdio.h>
int mystrlen(char* pch)
{
    if (!pch)
        return 0;
    
    int i=0;
    // int count;
    while(pch[i] != 0)
    {
        i++;
    }
    return i;
    
}

void min_max(int a, int b, int* min, int* max)
{
    *min = a;
    *max = b;
    if (a > b)
    {
        *min = b;
        *max = a;
    }
}

int* min(int a, int b)
{
    int min = a;
    if (a > b)
    {
        min = b;
    }
    return &min;
}

int main()
{
    int t = 5, w = 6, u, v;
    min_max(t, w, &u, &v);

    int x;
    scanf("%d", &x);
    printf("\nYou entered %d\n", x);
    // char buf[100] = "1234";
    // char buf2[1000] = "1234aa";
    // printf("%d\n", mystrlen(buf));
    // printf("%d\n", mystrlen(buf2));
    
}