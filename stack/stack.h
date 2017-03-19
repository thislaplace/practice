/*************************************************************************
	> File  : stack.h
	> Author: yuhao 
	> Mail  : yu.hao@utt.com.cn 
	> Time  : Sun 19 Mar 2017 03:22:56 AM EDT
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#endif

typedef strcut stack{
    char *data;
    struct stack *next;
}stack;

void initStack(stack *);
int isEmpty(stack *);
stack pushStack(satck *, stack *);
stack popStack(stack *);
