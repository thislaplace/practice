/****************************************************
 * File  : shmwrite.c
 * Author: yuhao
 * Mail  : yu.hao@utt.com.cn
 * Time  : Thu 04 May 2017 10:00:07 PM EDT
 */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include"shmdata.h"

int main()
{
    int isrunning = 1;

    int shmid = shmget((key_t)1234,sizeof(shmdata),0666|IPC_CREAT);
    if(shmid == -1)
    {
        fprintf(stderr,"shmid failed!\n");
        exit(EXIT_FAILURE);
    }

    void *shm = shmat(shmid,NULL,0);
    if(shm == (void*)-1)
    {
        fprintf(stderr,"shmat failed!\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout,"Memory attached at %p.\n",shm);

    shmdata* shared = (shmdata*)shm;

    while(isrunning)
    {
        while(shared->written == 1)
        {
            fprintf(stdout,"wait a moment.....\n");
            sleep(1);
        }

        fprintf(stdout,"Input some text: ");
        fgets(shared->text,TEXT_SIZE,stdin);
        shared->written = 1;

        if(!strncmp(shared->text,"end",3))
        {
            isrunning = 0;
        }

    }

    if(shmdt(shm) == -1)
    {
        fprintf(stderr,"shmdt failed!\n");
        exit(EXIT_FAILURE);
    }
    sleep(2);//等待另一个进程把这块内存释放掉再退出
    exit(EXIT_SUCCESS);
}
