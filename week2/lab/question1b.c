#include<stdio.h>

int slen(char* pch)
{
    int i = 0;
    for(; pch[i]; i++)
        ;
    return i;
}

void swap(char* pch, int p1, int p2)
{
    char t = pch[p1];
    pch[p1] = pch[p2];
    pch[p2] = t;
}

void reverse(char* pch)
{
    int len = slen(pch);
    for(int i=0; i<(len/2); i++)
        swap(pch, i, len-1-i);
}

int main()
{
    char buf[100];// = "1234567890";
    scanf("%s", buf);
    reverse(buf);
    printf("%s\n", buf);

    // char* buf1, buf2;

    return 0;
}