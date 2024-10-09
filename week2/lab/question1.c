#include<stdio.h>
#include<stdlib.h>

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

char* make_reverse_copy(char*pch)
{
    int len = slen(pch);
    char * buf = malloc(len+1);
    for(int i=0; i<len; i++)
        buf[i] = pch[i];
    buf[len]=0;
    reverse(buf);
    return buf;
}

// void make_reverse_copy(char*pch, char* buf)
// {
//     for(int i=0; i<100; i++)
//         buf[i] = pch[i];
//     reverse(buf);
// }


int main()
{
    char buf[100];
    // char buf_rev[100];
    scanf("%s", buf);
    // reverse(buf);
    char* buf_rev = make_reverse_copy(buf);
    printf("original: %s\n, reverse: %s\n", buf, buf_rev);
    free(buf_rev);
    return 0;
}