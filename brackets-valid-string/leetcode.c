#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char * s){
    char * opens = "[{(";
    size_t len = strlen(s);
    if(len <= 1 || strchr("[{(", s[0]) == NULL)
    {
        return false;
    }
    size_t stacklen = 1;
    char * closes = "]})";
    char * stack = malloc(len);
    stack[0] = s[0];
    for(int i = 1; i < len; ++i)
    {
        printf("%d", stacklen);
        if(strchr(opens, s[i]) != NULL)
        {
            stack[stacklen++] = s[i];
            continue;
        }
        if(stacklen == 0)
        {
            return false;
        }
        if(s[i] == ']' && stack[stacklen - 1] == '[')
        {
            stacklen--;
            continue;
        }
        if(s[i] == ')' && stack[stacklen - 1] == '(')
        {
            stacklen--;
            continue;
        }
        if(s[i] == '}' && stack[stacklen - 1] == '{')
        {
            stacklen--;
            continue;
        }
        return false;
    }
    if(stacklen == 0)
    {
        free(stack);
        return true;
    }
    free(stack);
    return false;
}

int main(int argc, char *argv[]) {
    for(int i = 0; i < argc; ++i)
    {
        if(isValid("(){}}{"))
        {
            return 0;
        }
        return 1;
    }
}