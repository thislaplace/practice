/**************************************************************************
* File  : factorize.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 16 Mar 2017 10:23:31 PM EDT
* 题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
*************************************************************************/
#include<stdio.h>
void factorize(int num);
int isPrime(int num);
int main(void)
{
	int num;
	printf("请输入要分解的整数：\n");
	scanf("%d",&num);
	factorize(num);
	return 0;
}

void factorize(int num)
{
	int i;
	if((num == 1) || (num == 2) || (num == 3))
		printf("%d ",num);
	for(i=3; i<num; ++i)
	{
		if(num%i == 0)
		{
			num = num/i;
			printf("%d*",i);
			break;
		}
	}
	if(isPrime(num))
	{
		printf("%d\n",num);
		return;
	}
	else
		factorize(num);
}

int isPrime(int num)
{
	int i,flag;
	flag = 1;
	for(i=num/2; i>=2; --i)
	{
		if(num%i == 0)
		{	
			flag = 0;
			break;
		}
	}
	if(flag)
		return 1;
	else
		return 0;
}
