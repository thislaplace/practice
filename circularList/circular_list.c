/**************************************************************************
* File  : circular_list.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Mon 20 Mar 2017 10:18:28 PM CST
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#ifndef _CIRLIST_H_
#include"circular_list.h"
#endif
void init(cirlist **l)
{
    *l = (cirlist*)malloc(sizeof(cirlist));
    (*l)->next = *l;
}

void addNode(cirlist *l,int data)
{
    if(l == NULL)
        return;
    cirlist *tmp = l;
    while(tmp->next != l)
        tmp = tmp->next;
    cirlist *newNode;
    newNode = (cirlist*)malloc(sizeof(cirlist));
    newNode->data = data;
    newNode->next = l;
    tmp->next = newNode;
}
void deletNode(cirlist *l,cirlist *node)
{
    if(l == NULL)
        return;
    cirlist *cur = l;
    while(l->next != node){
        l = l->next;
    }
    cur = l->next;
    l->next = cur->next;
    free(cur);
    cur = NULL;
}
void destory(cirlist **l)
{
    if((*l) == NULL)
        return;
    cirlist *tmp = *l;
    if(((*l)->next) != (*l))
    {
        tmp = *l;
        free(*l);
        *l = NULL;
        destory(&(tmp->next));
    }else
    {
        free(*l);
        *l = NULL;
    }
}
