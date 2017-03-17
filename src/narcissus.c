/**************************************************************************
* File  : narcissus.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 16 Mar 2017 10:11:03 PM EDT
* 题目：打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位
* 数字立方和等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方
* ＋5的三次方＋3的三次方。
*************************************************************************/
#include<stdio.h>
void narPrintf();

void main(void)
{
	narPrintf();
}

void narPrintf()
{
	int num,g,s,b;
	for(num=100; num<1000; num++)
	{
		b = num/(100);
		s = num%(100)/(10);
		g = num%(10);
		if((b*b*b+s*s*s+g*g*g) == num)
			printf("%d ",num);
	}
	printf("\n");
}
