/**************************************************************************
* File  : a.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Tue 09 May 2017 02:44:39 AM EDT
* 从键盘输入一个字符串，将小写字母全部转换成大写字母，然后输出到一个磁盘文件 “test”中保存。输入的字符串以！结束。
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
    char str[128];
    FILE *fp = NULL;
    int i = 0;

    memset(str, 0x0, sizeof(str));
    while(((str[i++] = getchar()) != '!')&&(i < 128));
    
    i = 0;
    while(str[i] != 0)
    {
        if ((str[i] >= 'a')&&(str[i] <= 'z'))
        {
            str[i] = str[i] + ('A' - 'a');
        }
        i++;
    }

    fp = fopen("./test","w+");
    fwrite(str,i,1,fp);
    fclose(fp);

    return 0;
}
