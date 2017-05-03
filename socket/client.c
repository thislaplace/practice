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
    //创建套接字
    char buffer[128];
    char str[128];
    int clnt_sock = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));  //每个字节都用0填充
    client_addr.sin_family = AF_INET;  //使用IPv4地址
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    client_addr.sin_port = htons(1234);  //端口
    while(1){
        connect(clnt_sock, (struct sockaddr*)&client_addr, sizeof(client_addr));

      
        printf("me:");
        fgets(buffer,128,stdin);

        send(clnt_sock,buffer,sizeof(buffer),0);
        recv(clnt_sock,str,sizeof(str),0);
        printf("server:");
        fputs(str,stdout);

        //关闭套接字
        memset(buffer,0x00,sizeof(buffer));
        memset(buffer,0x00,sizeof(str));
        close(clnt_sock);
    }
    
    return 0;
}
