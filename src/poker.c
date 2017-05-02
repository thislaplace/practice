/**************************************************************************
* File  : poker.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Tue 02 May 2017 03:01:48 AM EDT
*************************************************************************/
//猜牌术

#include<stdio.h>

int a[14];

int main()
{
    int i,j=1,count;
    for(i=1; i<=13; ++i)
    {
        count = 1;
        while(count<=i)
        {
            if(j != 13)
            j = j%13;

            if(a[j])
            ++j;
            else
            {
                if(count == i)
                a[j] = count;

                count++;
                j++;
            }
        }
    }

    for(i=1; i<14; ++i)
    printf("%d ",a[i]);

    return 0;
}
