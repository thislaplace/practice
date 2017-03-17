/**************************************************************************
* File  : prime.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 16 Mar 2017 09:39:33 PM EDT
* 题目：判断101-200之间有多少个素数，并输出所有素数。
*************************************************************************/
#include<stdio.h>
int numOfPrime();
void main(void)
{
	printf("The number of prime number is:%d.\n",numOfPrime());
}

int numOfPrime()
{
	int tmp,i,flag,n=0;
	for(tmp=101; tmp<200; ++tmp)
	{
		flag = 1;
		for(i=tmp/2; i>=2; --i)
		{
			if(tmp%i == 0)
			{	
				flag = 0;
				break;
			}
		}
		if(flag)
		n++;
	}

	return n;
}
