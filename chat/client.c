/**************************************************************************
* File  : client.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Sun 27 Aug 2017 11:11:23 PM EDT
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>
int sockfd;
char *IP = "192.168.10.200";
short PORT = 60111;
typedef struct sockaddr SA;
char name[30];


/*****************************************************
 * init client
 *****************************************************/
void init()
{
    printf("init\n");
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    printf("sockfd = %d\n", sockfd);
    struct sockaddr_in addr;
    memset(&addr, 0x0, sizeof(addr));
    addr.sin_family = PF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);

    if(connect(sockfd, (SA*)&addr, sizeof(addr)) == -1)
    {
        perror("connect to server failed\n");
        exit(-1);
    }

    printf("success to start client\n");
}


/*******************************************************
 * recieve Msg thread
 *******************************************************/
void *recv_thread(void *p)
{
    while(1)
    {
        char buf[100] = {};
        if(recv(sockfd, buf, sizeof(buf), 0) <= 0)
            return;
        printf("%s\n", buf);
    }
}


/*******************************************************
 * start client
 *******************************************************/
void start()
{
    pthread_t pid;
    pthread_create(&pid, 0, recv_thread, 0);
    char buf2[100] = {};
    sprintf(buf2, "%s connect to server", name);
    send(sockfd, buf2, strlen(buf2), 0);
    while(1)
    {
        char buf[100] = {};
        scanf("%s", buf);
        char msg[131] = {};
        sprintf(msg, "%s:%s", name, buf);
        send(sockfd, msg, strlen(msg), 0);
        if(strcmp(buf, "bye") == 0)
            break;
    }
    close(sockfd);
}


/********************************************************
 * main
 ********************************************************/
int main()
{
    init();
    printf("pleade put your name\n");
    printf("name:");
    scanf("%s", name);
    start();
    return 0;
}
