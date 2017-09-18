/**************************************************************************
* File  : shmread.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 04 May 2017 09:39:20 PM EDT
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include"shmdata.h"

int main()
{
    int isrunning = 1;

    int shmid = shmget((key_t)1234,sizeof(shmdata),0666|IPC_CREAT);
    if(shmid == -1)
    {
        fprintf(stderr,"shmget failed!\n");
        exit(EXIT_FAILURE);
    }
    perror("shmget");
    void *shm = shmat(shmid,NULL,0);
    if(shm == (void*)-1)
    {
        fprintf(stderr,"shmat failed!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout,"Memory attached at %p\n",shm);


    shmdata *shared = (shmdata*)shm;
    shared->written = 0;

    while(isrunning)
    {
        if(shared->written != 0)
        {
            fprintf(stdout,"someone wrote :%s",shared->text);
            if(strncmp(shared->text,"end",3)==0)
            {
                isrunning = 0;
            }
            shared->written = 0;
        }
        else
        {
            sleep(1);
        }
    }

    if(shmdt(shm) == -1)
    {
        fprintf(stderr,"shmdt failed!\n");
        exit(EXIT_FAILURE);
    }
    if(shmctl(shmid,IPC_RMID,0) == -1)
    {
        fprintf(stderr,"shmctl failed!\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
