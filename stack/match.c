/*************************************************************************
	> File  : match.c
	> Author: yuhao 
	> Mail  : yu.hao@utt.com.cn 
	> Time  : Sun 19 Mar 2017 06:09:20 AM EDT
 ************************************************************************/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#ifndef _STACK_H_
#include"stack.h"
#endif
int match(char *str)
{
    stack *s;
    initStack(&s);
    while(*str != '\0')
    {
        switch(*str)
        {
            case '(' :
            case '[' :
            case '{' :
            {   
                s = pushStack(s,str);
                break;
            }
            case ')' :
            {   
                if(*(s->data) == '(')
                   s = popStack(s);
                else
                   return 0;
                break;
            }
            case ']' :
            {   
                if(*(s->data) == '[')
                   s = popStack(s);
                else
                   return 0;
                 break;
            }
            case '}' :
            {
                if(*(s->data) == '{')
                   s = popStack(s);
                else
                   return 0;
                break;
            }
            default :
                break;
        }
        str++;
    }
        return isEmpty(s);
}


int main()
{
    char *str;
    str = (char *)malloc(128);
    printf("Please input some str:\n");
    fgets(str,100,stdin);
    if(match(str))
        printf("Match\n");
    else
        printf("Do not match\n");
}
