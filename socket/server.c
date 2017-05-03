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
int main(){
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int clnt_sock = 0;
    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //进入监听状态，等待用户发起请求
    //接收客户端请求
    listen(serv_sock, 20);
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    while(1){
      

        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        printf("%d ",clnt_sock);

        char str[128];
        int strlen = recv(clnt_sock, str, sizeof(str), 0);
        send(clnt_sock, str, strlen, 0);
        //关闭套接字
        memset(str,0x00,sizeof(str));
        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
