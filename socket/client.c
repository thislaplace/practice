/**************************************************************************
* File  : client.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Mon 01 May 2017 09:26:19 PM EDT
*************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
    char buffer[128];
    char Msg[130];
    int clnt_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = PF_INET;
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    client_addr.sin_port = htons(60111);
    while(!connect(clnt_sock, (struct sockaddr*)&client_addr, sizeof(client_addr)))
    while(1){
        bzero(Msg, sizeof(Msg));
        printf("me:");
        fgets(Msg, sizeof(Msg), stdin);
        send(clnt_sock, Msg, strlen(Msg), 0);
    }

    close(clnt_sock);
    return 0;
}
