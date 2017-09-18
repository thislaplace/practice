/**************************************************************************
* File  : server.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Sun 27 Aug 2017 09:52:07 PM EDT
*************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<pthread.h>

int sockfd;
int fds[100];
int size = 100;
char *IP = "192.168.10.200";
short PORT = 60111;
typedef struct sockaddr SA;

/******************************************
 * init socket
 ******************************************/
void init(){
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("socket creat failed");
        exit(-1);
    }
    struct sockaddr_in addr;
    addr.sin_family = PF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);

    if(bind(sockfd, (SA*)&addr, sizeof(addr)) == -1)
    {
        perror("bind socket falied");
        exit(-1);
    }

    if(listen(sockfd, 100) == -1)
    {
        perror("set listen failed");
        exit(-1);
    }
}


/***************************************
 * send Msg
 ***************************************/
void sendMsg(char *msg)
{
    int i;
    for(i=0; i<size; ++i)
    {
        if(fds[i] != 0)
        {
            send(fds[i], msg, strlen(msg), 0);
        }
    }
}


/*********************************************
 * service thread
 *********************************************/
void *service_thread(void *p)
{
    int fd = *(int *)p;
    printf("pthread = %d\n", fd);
    while(1)
    {
        char buf[128] = {};
        if(recv(fd, buf, sizeof(buf), 0) <= 0)
        {
            int i;
            for(i=0; i<size; ++i)
            {
                if(fd == fds[i])
                {
                    fds[i] = 0;
                    break;
                }
            }
            printf("quit:fd = %d\n", fd);
            pthread_exit(-1);
        }
        sendMsg(buf);
    }
}


/**********************************************
 * start service
 **********************************************/
void service()
{
    printf("start service\n");
    while(1)
    {
        struct sockaddr_in fromaddr;
        socklen_t len = sizeof(fromaddr);
        int fd = accept(sockfd, (SA*)&fromaddr, &len);
        if(fd == -1)
        {
            printf("client connect failed\n");
            continue;
        }
        
        int i = 0;
        for(i=0; i<size; ++i)
        {
            if(fds[i] == 0)
            {
                fds[i] = fd;
                printf("fd = %d\n", fd);
                pthread_t tid;
                pthread_create(&tid, 0, service_thread, &fd);
                break;
            }
            if(size == i)
            {
                char *str = "chat is full";
                send(fd, str, strlen(str), 0);
                close(fd);
            }
        }
    }
}


/*********************************************
 * main
 *********************************************/
int main()
{
    init();
    service();
}
