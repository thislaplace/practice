/**************************************************************************
* File  : rabit.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 16 Mar 2017 09:35:35 PM EDT
* 题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔
* 子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数
* 为多少？
*************************************************************************/
#include<stdio.h>
#include<stdio.h>
 
int numOfRabit(int n);

int main()
{
   int n;
   printf("Input the number:");
   scanf("%d",&n);
   printf("the number of rabit is :%d.\n",numOfRabit(n));
    return 0;
}
 
 int numOfRabit(int n)
 {
    if((n == 1) || (n == 2))
         return 1;
    else
         return numOfRabit(n-1)+numOfRabit(n-2);
}
