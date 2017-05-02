/**************************************************************************
* File  : calcul.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Sat 25 Mar 2017 01:42:11 AM CST
*************************************************************************/
#include<stdio.h>
#ifndef _CALCUL_H
#include<calcul.h>
#endif
void init_dataStack(dataStack *s)
{
    s->top = -1;
}

void init_operatorStack(operator *s)
{
    s->top = -1;
}

int is_dataStack_Empty(dataStack *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int is_operatorStack_Empty(operatorStack *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int get_dataStack_top(dataStack *s)
{
    if(s->top <= 0){
        printf("当前栈已空！");
        exit(-1);
    }
    return s->data[top];
}

char get_operatorStack_top(operatorStack *s)
{
    if(s->top <= 0){
        printf("当前栈已空！");
        exit(-1);
    }
    return s->str[top];
}
