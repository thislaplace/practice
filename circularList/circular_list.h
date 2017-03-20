#include<stdio.h>
#ifndef _CIRLIST_H_
#define _CIRLIST_H_
#endif
typedef struct cirlist{
    int data;
    struct cirlist *next;
}cirlist;
