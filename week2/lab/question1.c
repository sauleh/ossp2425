#include<stdio.h>

int slen(char* pch)
{
    int len = 0;
    while(*pch) {
        len++;
        pch++;
    }
    return len;
}

void reverse(char* pch)
{
    int len = slen(pch);
    for(int i=0; i<(len/2); i++)
    {
        char t = pch[i];
        pch[i] = pch[len-1-i];
        pch[len-1-i] = t;
    }
}

int main()
{
    char buf[100];
    scanf("%s", buf);
    reverse(buf);
    printf("%s\n", buf);
    return 0;
}