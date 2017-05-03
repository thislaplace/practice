/**************************************************************************
* File  : peach.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 03 May 2017 03:02:02 AM EDT
* 五只猴子分桃
*************************************************************************/
#include<stdio.h>
int main()
{
    int i = 1;
    int j,flag = 1, tmp;

    for(j=25*25; j<10000; ++j)
    {
        tmp = j;
        for (i=1; i<=5; ++i)
        {
            if(tmp%5 == 1)
            {
                tmp = tmp - 1 - tmp/5;
            }
            else
            {
                break;
            }
        }
        if(i == 6)
            printf("%d\n",j);
    }
    return 0;
}
