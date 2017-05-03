/**************************************************************************
* File  : strlen.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 03 May 2017 02:29:42 AM EDT
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int len = 0;
    char *str = NULL;
    str = (char*)malloc(sizeof(char)*100);
    fgets(str,100,stdin);//这里会把回车符也录入

    char * tmp = str;
    while(*tmp++ != '\0')
        len++;

    printf("%d\n",len-1);//所以这里要减一
    
    free(str);
    str = NULL;
    return 0;
}
