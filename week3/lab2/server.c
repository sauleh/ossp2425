#include "server_helper.h"

void usage()
{
    printf("server.exe -i or\n server.exe <portnumber>\n");
}

// public static main(string[] args)
int main(int argc, char** argv)
{
    CmdArg cmd;
    // int argc = 2;
    // char* argv[2] = {"server.exe", "1234"};

    if (!process_args(argc, argv, &cmd))  
    {
        usage();
        return -1;
    }
    if (cmd.is_interactive)
        run_interactive(&cmd);
    else
        run_listen(&cmd);
    return 0;
}

















//TODO1 true/false ()
    //TODO2 write usage() function
    //TODO3 call usage() if process_args failes
