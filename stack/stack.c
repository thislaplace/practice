/*************************************************************************
> File  : stack.c
> Author: yuhao 
> Mail  : yu.hao@utt.com.cn 
> Time  : Sun 19 Mar 2017 03:22:42 AM EDT
************************************************************************/

#include<stdio.h>
#ifndef _STACK_H_
#include"stack.h"
#endif
void initStack(stack **top)
{
    *top = (stack*)malloc(sizeof(stack));
    *top->data = "top";
    *top->next = NULL;
}

int isEmpty(satck *top)
{
    if(top->next == NULL)
        return 1;
    else
        return 0;
}

stack * pushSatck(stack *top, stack *node)
{
    node->next = top->next;
    return node;
}

stack *popStack(stack *top)
{
    if(top->next == NULL)
        return;
    top = top->next;
    return top;
}
