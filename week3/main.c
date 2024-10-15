#include<stdio.h>
#include<stdlib.h>

typedef struct _rule{
    char ip[4];
    unsigned short int port;
    struct _rule* next;
} Rule;

void print_ll(Rule* p)
{
    while (NULL != p)
    {
        printf("%d => ", p->port);
        p = p->next;
    }
    printf("\n");
}

Rule* add_ll(Rule* pHead, unsigned short int port)
{
    Rule* newNode = malloc(sizeof(Rule));
    newNode->port = port;
    newNode->next = NULL;
    if (NULL == pHead)
        return newNode;
    
    newNode->next = pHead;
    return newNode;
}

int main3()
{
    Rule* pHead = NULL;
    print_ll(pHead);
    pHead = add_ll(pHead, 2);
    print_ll(pHead);
    pHead = add_ll(pHead, 5);
    print_ll(pHead);
    // TODO 1: add end
    // TODO 2: delete
    // TODO 3: find
    // TODO 4: free linked list
}















typedef long long int STDNO;

typedef struct _pair {
    int a;
    int b;
    char buf[20];
    double d;
    struct pair* pp;
    int x;
} Pair;

typedef struct _big {
    int nums[300000];
    int len;
    int sum;
} Big;


void update(Big* b)
{
    b->sum = 0;
    for(int i=0; i<b->len; i++)
        (*b).sum += b->nums[i];
}

void print_pair(Pair p)
{
}

int main()
{
    Big* b = malloc(sizeof(Big));
    b->nums[0] = 5;
    b->nums[1] = 7;
    b->len = 2;
    printf("worked!\n");
    update(b);
    printf("worked sum=%d!\n", b->sum);

    return 0;
    STDNO x;
    Pair mypair;

    mypair.a = 0xaaffaaff;
    mypair.b = 0xffffaaaa;
    mypair.buf[0] = 'A';
    mypair.buf[1] = 0;
    mypair.d = 1.1;
    free(b);
    return 0;
}