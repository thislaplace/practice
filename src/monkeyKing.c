/**************************************************************************
* File  : monkey.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Mon 20 Mar 2017 07:54:04 PM CST
*************************************************************************/
#include<stdio.h>
void monkeyKing(int monkeyNum)
{
    int a[1000];
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

int main()
{
    int monkeyNum;
    printf("输入猴子的个数：\n");
    scanf("%d",&monkeyNum);
    monkeyKing(monkeyNum);
    return 0;
}
