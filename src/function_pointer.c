/*
 * File Name: test.c
 * Author: laplace
 * Mail: 17756591673@163.com
 * Created Time: 2017年10月15日 星期日 10时22分33秒
 */

#include<stdio.h>

int func1(int a, int b)
{
    printf("This is func1\n");
    printf("a + b = %d\n", a+b);
}


int *func()
{
    printf("func1 = %p\n", func1);
    return func1;
}


typedef struct test{
    int (*function)();
}test;


test T = {
    .function = func(),
};


int main()
{
    int a = 1;
    int b = 2;

    T.function(a, b);

    return 0;
}
