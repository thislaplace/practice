/**************************************************************************
* File  : server.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Mon 01 May 2017 09:24:37 PM EDT
*************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int client_sock = 0;
    char str[128];

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(60111);
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(serv_sock, 20);
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int strlen;
    while(1){
        client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &client_addr_size);
        memset(str, 0, sizeof(str));
        strlen = recv(client_sock, str, sizeof(str), 0);
        printf("%08x say: %s\n",client_addr.sin_addr.s_addr, str);
    }
    close(serv_sock);
    return 0;
}
