#include<stdio.h>
#include<stdlib.h>

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

void make_reverse_copy(char* pch, char* buf)
{
    for(int i=0; i<100; i++)
        buf[i] = pch[i];
    reverse(buf);
}

char* make_reverse_copy_dynamic(char* pch)
{
    int len = slen(pch);
    char* buf = malloc(sizeof(char) * (len+1));
    for(int i=0; i<len; i++)
        buf[i] = pch[i];
    buf[len] = 0;
    reverse(buf);
    return buf; 
}

int main()
{
    char buf[100];// = "1234567890";
    // char rev_buf[100];
    scanf("%s", buf);
    // reverse(buf);
    char* rev_buf = make_reverse_copy_dynamic(buf);
    printf("original: %s\nreverse: %s", buf, rev_buf);
    free(rev_buf);
    return 0;
}