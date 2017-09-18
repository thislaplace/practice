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
    int clnt_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = PF_INET;
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    client_addr.sin_port = htons(60111);
    while(!connect(clnt_sock, (struct sockaddr*)&client_addr, sizeof(client_addr)))
    {
        printf("try to connect to server\n");
    }
    while(1){
        memset(buffer, 0x0, sizeof(buffer));
        printf("me:");
        fgets(buffer, sizeof(buffer), stdin);
        char Msg[130] = {0};
        sprintf(Msg, "%s", buffer);
        send(clnt_sock, Msg, strlen(Msg), 0);
    }
    printf("over");
    close(clnt_sock);
    
    return 0;
}
