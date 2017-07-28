/**************************************************************************
* File  : test.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 27 Jul 2017 11:43:54 PM EDT
*************************************************************************/
#include<stdio.h>
#include<pthread.h>
static pthread_mutex_t test_lock;
pthread_t test_thread;

void test()
{
    pthread_mutex_lock(&test_lock);
    printf("mutex is locked by test\n");
    pthread_mutex_unlock(&test_lock);
    printf("mutex is unlocked by test\n");
    
    return;
}

int main()
{
    pthread_mutex_init(&test_lock, NULL);
    pthread_mutex_lock(&test_lock);
    printf("mutex is locked by main\n");
    pthread_create(&test_thread, NULL, test, NULL);
    sleep(2);
    pthread_mutex_unlock(&test_lock);
    printf("mutex is unlocked by main\n");

    /*等待线程执行结束，回收线程的资源*/
    pthread_join(test_thread, NULL);
    pthread_mutex_destroy(&test_lock);

    return 0;
}
