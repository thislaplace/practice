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
void initStack(stack **top)
{
    *top = (stack*)malloc(sizeof(stack));
    (*top)->data = "top";
    (*top)->next = NULL;
}

int isEmpty(stack *top)
{
    if(top->next == NULL)
        return 1;
    else
        return 0;
}

stack *pushStack(stack *top, char *data)
{
    stack *newNode;
    newNode = (stack *)malloc(sizeof(stack));
    newNode->data = data;
    newNode->next = top->next;
    return newNode;
}

stack *popStack(stack *top)
{
    if(top->next == NULL)
        return;
    top = top->next;
    return top;
}
