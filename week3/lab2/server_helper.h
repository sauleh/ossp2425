#include<stdbool.h>
#include<stdio.h>
#include<string.h>

#define FW_MAX_CMD 255

typedef struct _CmdArg {
    bool is_interactive;
    int port;
} CmdArg;

typedef struct _FwCmd {
    char RawCmd[FW_MAX_CMD];
    char Cmd;
    FwRequest* pNext;
} FwRequest;

typedef struct _FwRule {
    // ipaddress 1, 2
    // port 1, 2
    FwRule* pNext;
} FwRule;


bool is_digit(char ch)
{
    return ((ch >= '0') && ( ch <= '9'));
}

int powi(int n, int p)
{
    int result = 1;
    for(int i=0; i<p; i++)
        result *= n;
    return result;
}

bool is_integer(char* pch, int* num)
{
    *num = 0;
    for(int i=0; i<strlen(pch); i++)
    {
        if (is_digit(pch[i]))
        {
            *num += powi(10,i)*(pch[i]-48);
        }
        else
            return false;
    }
    return true;
}

bool process_args(int argc, char** argv, CmdArg* pcmd)
{
    if (argc != 2)
        return false;

    bool bSuccess = false;
    pcmd->is_interactive = false;
    pcmd->port = 0;
    if (strcmp(argv[1], "-i") == 0)
    {
        pcmd->is_interactive = true;
        bSuccess = true;
    }     
    else
    {
        if (is_integer(argv[1], &(pcmd->port)))
        {
            pcmd->is_interactive = false;
            bSuccess = true;
        }
    } 
    return bSuccess;
}

void run_interactive(CmdArg* pcmd)
{
    char line[255];
    FwRule * fwRuleHead = NULL;
    FwRequest* fwReqHead = NULL;
    while(true)
    {
        fgets(line, 255, stdin);
        FwRequest* fwReq = process_cmd(line);
        switch (fwReq->Cmd)
        {
        case 'A':
            run_add_cmd(fwReq ,fwRuleHead);
            break;

        case 'D':
            run_del_cmd(fwReq, fwRuleHead);
            break;

        case 'L':
            run_list_cmd(fwReq, fwRuleHead);
            break;

        case 'R':
            run_list_requests_cmd(fwReq, fwReqHead);
            break;

        case 'C':
            run_check_cmd(fwReq, fwRuleHead);
            break;

        default:
            break;
        }
    }
}

void run_listen(CmdArg* pcmd)
{
    printf("run server listening on port %d\n", pcmd->port);

}