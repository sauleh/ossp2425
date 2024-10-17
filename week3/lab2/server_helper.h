#include<stdbool.h>
#include<stdio.h>
#include<string.h>

typedef struct _CmdArg {
    bool is_interactive;
} CmdArg;

void process_args(int argc, char** argv, CmdArg* pcmd)
{
    pcmd->is_interactive = false;
    if (argc == 2)
    {
        if (strcmp(argv[1], "-i") == 0)
        {
            pcmd->is_interactive = true;
        }        
    }
}

void run_interactive(CmdArg* pcmd)
{
    printf("run server interacive\n");
}

void run_listen(CmdArg* pcmd)
{
    printf("run server listen\n");

}