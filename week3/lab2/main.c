#include<stdio.h>
#include "temp.h"

#define DEFAULT 0
#define pn(x) printf("%d\n",x)

int main()
{    
    int w = DEFAULT;
    int x = add(5, 4);
    // printf("%d\n", x);
    pn(x);
    return 0;
}