/*************************************************************************
	> File  : perfectNum.c
	> Author:yuhao 
	> Mail  :yu.hao@utt.com.cn 
	> Time  : Fri 17 Mar 2017 10:14:59 AM EDT
    >题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2
    >＋3.编程找出1000以内的所有完数。
 ************************************************************************/

#include<stdio.h>
int perfectNum(int n);
int main()
{
    int n,i;
    printf("输入一个数字：\n");
    scanf("%d",&n);
    printf("%d以内的完数有：",n);
    for(i=1; i<=n; ++i)
    {
        if(perfectNum(i))
        {
            printf("%d ",i);
        }
    }
    printf(".\n");
    return 0;
}

int perfectNum(int n)
{
    int sum=0,i;
    for(i=1; i<n; ++i)
    {
        if(n%i == 0)
        {
            sum = sum + i;
            continue;
        }
    }
    if(sum == n)
        return 1;
    else
        return 0;
}
