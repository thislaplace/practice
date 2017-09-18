/**************************************************************************
* File  : monkey.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Mon 20 Mar 2017 07:54:04 PM CST
*************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void monkeyKing(int monkeyNum)
{
    int a[10000];
    int i, monkeyLeft=monkeyNum, count=0;
    for(i=0; i<monkeyNum; ++i)
    {
        a[i] = 1;
    }
    i = 0;
    while(monkeyLeft != 1)
    {
        if(a[i] == 1)
        {
            count++; 
            if(count == 3)
            {
                count = 0;
                a[i] = 0;
                monkeyLeft--;
            }
        }
        i = (i+1)%monkeyNum;
    }
    for(i=0; i<monkeyNum; ++i)
    {
        if(a[i] == 1)
            printf("The King is %d.\n",i+1);
    }
}

void input(int *monkeyNum)
{
    char *str;
    str = (char*)malloc(150);
    printf("请输入一个数字：\n");
    fgets(str,128,stdin);
    *monkeyNum = atoi(str);
    free(str);
    str = NULL;
    if(monkeyNum > 0)
    {}
    else
    {
        printf("输入错误，请重新输入：\n");
        input(monkeyNum);
    }
}

int main()
{
    int monkeyNum; 
    input(&monkeyNum);
    monkeyKing(monkeyNum);
    return 0;
}
