/**************************************************************************
* File  : bitopera.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 03 May 2017 01:48:12 AM EDT
* 位运算
*************************************************************************/
#include<stdio.h>
#include<string.h>
int main()
{
    unsigned a,b,c,d;
    scanf("%o",&a);
    b=a>>4;
    c=~(~0<<4);
    d=b&c;
    printf("%c\n",d);
    return 0;
}
