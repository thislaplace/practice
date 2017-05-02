/**************************************************************************
* File  : endian.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Tue 02 May 2017 04:13:31 AM EDT
*************************************************************************/
//大小端判断
#include<stdio.h>
#include<stdint.h>
int main()
{
    uint16_t num;
    char num1,num2;
    num = 0x1122;
    num1 = ((char *)&num)[0];
    num2 = ((char *)&num)[1];
    
    printf("num1=%x ,num2=%x\n",num1,num2);
    return 0;
}

