/*************************************************************************
	> File  : score.c
	> Author:yuhao 
	> Mail  :yu.hao@utt.com.cn 
	> Time  : Fri 17 Mar 2017 08:57:45 AM EDT
    > 题目：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60
    > -89分之间的用B表示，60分以下的用C表示。
 ************************************************************************/
void rank(int score);
#include<stdio.h>
int main()
{
    int score;
    printf("请输入你的成绩：\n");
    scanf("%d",&score);
    rank(score);
    return 0;
}

void rank(int score)
{
    char grade;
    grade = score >= 90 ? 'A' : (score >= 60 ? 'B' : 'C');//最垃圾的写法，但是题目这么要求没办法。
    printf("Your score belongs to %c.\n",grade);
}
