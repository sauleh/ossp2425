#include<stdio.h>
#include"server_helper.h"

int main(int argc, char** argv)
{
    CmdArg cmd;
    memset(&cmd, 0, sizeof(CmdArg));
    if (!process_args(argc, argv, &cmd))
    {
        print_usage();
        return 1;
    }
    if (cmd.is_interactive)
        run_interactive();
    else
        run_server();

    return 0;
}