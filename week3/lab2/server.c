#include "server_helper.h"

// public static main(string[] args)
int main(int argc, char** argv)
{
    CmdArg cmd;
    process_args(argc, argv, &cmd); //TODO1 true/false ()
    //TODO2 write usage() function
    //TODO3 call usage() if process_args failes
    if (cmd.is_interactive)
        run_interactive(&cmd);
    else
        run_listen(&cmd);
    return 0;
}