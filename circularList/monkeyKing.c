/**************************************************************************
* File  : monkeyKing.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Mon 20 Mar 2017 10:34:31 PM CST
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef _CIRLIST_H_
#include"circular_list.h"
#endif
void monkeyKing(int monkeyNum);
void input(int *);
int main()
{
    int monkeyNum;
    input(&monkeyNum);
    monkeyKing(monkeyNum);
    return 0;
}
void input(int *monkeyNum)
{
    char *str;
    str = (char*)malloc(128);
    printf("输入猴子的数量：\n");
    fgets(str,100,stdin);
    *monkeyNum = atoi(str);
    if(*monkeyNum>0)
        printf("OK\n");
    else{
        printf("输入有误，请重新输入：\n");
        input(monkeyNum);
    }
    free(str);
    str = NULL;
}
void monkeyKing(int monkeyNum)
{
    int count = 1;
    int i;
    cirlist *l;
    init(&l);
    l->data = 1;
    for(i=1; i<monkeyNum; ++i)
    {
        addNode(l,i+1);
    }
    while(l->next != l)
    {
        if(count == 3)
        {
            deletNode(l,l);
            count = 0;
        }
        l = l->next;
        count++;
    }
    printf("猴子大王是：%d.\n",(l->data));
    destory(&l);
}
