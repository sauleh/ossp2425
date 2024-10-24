typedef struct _ds
{
    int a;
    int b;
    char buf[10];
    char * buf;
} DS;

int main()
{
    DS ds;
    memset(&ds, sizeof(ds), 0);
    DS* pds = malloc(sizeof(ds));
    memset(pds, sizeof(ds), 0);
}