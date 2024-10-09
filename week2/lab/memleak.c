#include<stdlib.h>
#include<stdio.h>
#include<windows.H>

int main()
{
    char* pch;
    for(int i=0; i<10000000; i++)
    {
        pch = malloc(1000000);
        Sleep(100);
        free(pch);
    }
    return 0;
}