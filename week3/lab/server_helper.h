#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <arpa/inet.h>

typedef struct _CmdArg
{
    bool is_interactive; 
    int server_port;
} CmdArg;

typedef struct _Rule
{
    int x;
    /* data */
} Rule;

typedef struct _Request
{
    int x;
    /* data */
} Request;

bool process_args(int argc, char** argv, CmdArg* pCmd)
{
    if (argc <= 1)
        return false;

    if (argc == 2)
    {
        if (strcmp(argv[1], "-i") == 0)
            pCmd->is_interactive = true;
    }
    return true;
}

void get_socket_handles(int* server_fd, int* new_socket, CmdArg* cmd)
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    *server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(cmd->server_port);
    bind(*server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(*server_fd, 3);
    *new_socket = accept(*server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
}

void parse_rule(char* pchRule, Rule* rule)
{}

char* make_str(const char* pch)
{
    int memSize = strlen(pch) + 1;
    char* pchR = malloc(memSize);
    for(int i=0; i<memSize; i++)
        pchR[i] = pch[i];
    return pchR;                
}

// TODO update function signatures and also implement
char* process_add_rule(char* pch, Rule* pRuleHead){}
char* process_delete_rule(char* pch, Rule* pRuleHead){}
char* process_rule_list(char* pch, Rule* pRuleHead){}
char* process_requests_list(char* pch, Request* pRequestHead){}
char* process_rule_check(char* pch, Rule* pRuleHead){}

void  run_server(int inHandle, int outHandle)
{
    char line[1024];
    Rule* pRuleHead = NULL;
    Request* pRequestHead = NULL;
    while(true)
    {
        // TODO update pRequestHead
        int len = read(inHandle, line, 1024);
        char* response = NULL;
        switch (line[0])
        {
        case 'A':
            response = process_add_rule(line, pRuleHead);
            break;
        
        case 'D':
            response = process_delete_rule(line, pRuleHead);
            break;
        
        case 'L':
            response = process_rule_list(line, pRuleHead);
            break;
        
        case 'R':
            response = process_requests_list(line, pRequestHead);
            break;
        
        case 'C':
            response = process_rule_check(line, pRuleHead);
            break;
        
        default:
            response = make_str("Illegal Request");
            break;
        }
        write(outHandle, response, strlen(response));
        free(response);
        response = NULL;
    }
}


void print_usage()
{
    printf("usage is ....\n");
}
