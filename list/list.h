/**************************************************************************
 * * File  : list.h
 * * Author: yuhao
 * * Mail  : yu.hao@utt.com.cn
 * * Time  : Thu 16 Mar 2017 06:18:37 PM CST
 * *************************************************************************/
int n = 6;

typedef struct student {
    int num;
    char * name;
    struct student *next;
}student;

