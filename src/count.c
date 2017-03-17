/*************************************************************************
	> File  : count.c
	> Author:yuhao 
	> Mail  :yu.hao@utt.com.cn 
	> Time  : Fri 17 Mar 2017 09:30:32 AM EDT
    >题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数
 ************************************************************************/

#include<stdio.h>

int main()
{
    int letter=0,space=0,num=0,other=0;//不要忘记初始化，编译器可能不会帮你初始化
    char c;
    printf("请输入一串字符，以回车结束输入：\n");
    while((c=getchar()) != '\n')
    {
        if((c>'a' && c<'z')||(c>'A' && c<'Z'))
            letter++;
        else if(c == ' ')
            space++;
        else if(c>'0' && c<'9')
            num++;
        else
            other++;
    }
    printf("这串字符中有%d个字母，%d个数字，%d个空格，还有%d个其他字符。\n",letter,num,space,other);
    return 0;
}
