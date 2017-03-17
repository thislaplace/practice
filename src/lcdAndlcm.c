/*************************************************************************
	> File  : lcdAndlcm.c
	> Author:yuhao 
	> Mail  :yu.hao@utt.com.cn 
	> Time  : Fri 17 Mar 2017 09:09:58 AM EDT
    >题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
 ************************************************************************/

#include<stdio.h>
int lcd(int m, int n);
int lcm(int m, int n);
int main()
{
    int m,n;
    printf("请输入两个正整数,中间用空格隔开：\n");
    scanf("%d %d",&m,&n);
    printf("最大公约数是：%d.\n",lcd(m,n));
    printf("最小公倍数是：%d.\n",lcm(m,n));
    return 0;
}

int lcd(int m,int n)
{
    int max = m>n?m:n;
    int min = m>n?n:m;
    int i;
    for(i=min; i>1; --i)
    {
        if((min%i == 0) && (max%i == 0))
        {
            return i;
        }
    }
    return 0;
}

int lcm(int m, int n)
{
    int max = m>n?m:n;
    int min = m>n?n:m;
    int tmp;
    for(tmp=max;;++tmp)
    {
        if((tmp%max == 0) && (tmp%min == 0))
            return tmp;
    }
    return 0;
}

