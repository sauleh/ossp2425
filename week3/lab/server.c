#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server_helper.h"

int main(int argc, char** argv)
{
    CmdArg cmd;
    memset(&cmd, 0, sizeof(CmdArg));
    if (!process_args(argc, argv, &cmd))
    {
        print_usage();
        return 1;
    }

    int inHandle = STDIN_FILENO, outHandle = STDOUT_FILENO, server_fd = -1, new_socket = -1;
    if (!cmd.is_interactive)
    {
        get_socket_handles(&server_fd, &new_socket, &cmd);
        inHandle = outHandle = new_socket;
    }

    run_server(inHandle, outHandle);

    return 0;
}