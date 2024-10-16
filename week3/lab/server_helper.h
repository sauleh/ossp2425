#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct _CmdArg
{
    bool is_interactive; 
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

void run_interactive()
{
    printf("running interactive mode\n");
}

void parse_rule(char* pchRule, Rule* rule)
{}

// TODO update function signatures and also implement
void process_add_rule(char* pch){}
void process_delete_rule(char* pch){}
void process_rule_list(char* pch){}
void process_requests_list(char* pch){}
void process_rule_check(char* pch){}

void  run_server()
{
    char line[256];
    Rule* pRuleHead = NULL;
    Request* pRequestHead = NULL;
    while(true)
    {
        // TODO update pRequestHead
        fgets(line, 256, stdin);
        switch (line[0])
        {
        case 'A':
            process_add_rule(line, pRuleHead);
            break;
        
        case 'D':
            process_delete_rule(line, pRuleHead);
            break;
        
        case 'L':
            process_rule_list(line, pRuleHead);
            break;
        
        case 'R':
            process_requests_list(line, pRequestHead);
            break;
        
        case 'C':
            process_rule_check(line, pRuleHead);
            break;
        
        default:
            printf("Illegal request");
            break;
        }
    }
}


void print_usage()
{
    printf("usage is ....\n");
}
