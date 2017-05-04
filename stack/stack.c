/*************************************************************************
> File  : stack.c
> Author: yuhao 
> Mail  : yu.hao@utt.com.cn 
> Time  : Sun 19 Mar 2017 03:22:42 AM EDT
************************************************************************/
#include<stdlib.h>
#ifndef _STACK_H_
#include"stack.h"
#endif
void initStack(stack **s)
{
    *s = (stack*)malloc(sizeof(stack));
    (*s)->data = "bottom";
    (*s)->next = NULL;
}

int isEmpty(stack *s)
{
    if(s->next == NULL)
        return 1;
    else
        return 0;
}

stack *pushStack(stack *s, char *data)
{
    stack *newNode;
    newNode = (stack *)malloc(sizeof(stack));
    newNode->data = data;
    newNode->next = s;
    return newNode;
}

stack *popStack(stack *s)
{
    if(s->next == NULL)
        return;
    stack *tmp = s;
    s = s->next;
    free(tmp);
    return s;
}
