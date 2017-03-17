/*************************************************************************
	> File  : add.c
	> Author:yuhao 
	> Mail  :yu.hao@utt.com.cn 
	> Time  : Fri 17 Mar 2017 09:48:12 AM EDT
    >题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如
    >2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
    >键盘录入两个数字意义不大，就写2+22+.....了
 ************************************************************************/

#include<stdio.h>
int result(int n);
int main()
{
    int n;
    printf("输入一个大于1的整数：\n");
    scanf("%d",&n);
    printf("结果是：%d.\n",result(n));
    return 0;
}
int result(int n)
{
    int numN=0,i;
    
    if(n == 1)
        return 2;
    else
    {
        for(i=0; i<n ;++i)
        {
            numN = numN*10 + 2;
        }
        return numN + result(n-1);
    }
    return 0;//防止编译器警告
}
