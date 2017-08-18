/**************************************************************************
* File  : ping.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Fri 18 Aug 2017 03:14:26 AM EDT
*************************************************************************/
#include<stdio.h>  
#include<stdlib.h>  
#include<sys/time.h>  
/*是Linux系统的日期时间头文件*/  
/*是POSIX标准定义的unix类系统定义符号常量的头文件，
包含了许多UNIX系统服务的函数原型，例如read函数、
write函数和getpid函数*/  
#include<unistd.h> 
#include<string.h>  
#include<sys/socket.h>    /*对与引用socket函数必须*/  
#include<sys/types.h>  
#include<netdb.h> /*定义了与网络有关的结构，变量类型，宏，函数。函数gethostbyname()用*/  
#include<errno.h> /*sys/types.h中文名称为基本系统数据类型*/  
#include<arpa/inet.h> /*inet_ntoa()和inet_addr()这两个函数，包含在 arpa/inet.h*/  
#include<signal.h>    /*进程对信号进行处理*/  
#include<netinet/in.h>    /*互联网地址族*/  
#include"ping.h"  
#define IP_HSIZE sizeof(struct iphdr)   /*定义IP_HSIZE为ip头部长度*/  
#define IPVERSION  4   /*定义IPVERSION为4，指出用ipv4*/  

struct itimerval val_alarm={
    .it_interval.tv_sec = 1,
    .it_interval.tv_usec = 0,
    .it_value.tv_sec = 0,
    it_value.tv_usec = 1
};

int main(int argc, char *argv[])
{
    struct hostent *host;
    int on = 1;
    if(argc < 2){
        printf("usage:
        /t%s hostname\n", argv[0]);
        exit(1);
    }

    if((host=gethostbyname(argv[1]))==NULL)
    {
        perror("can not understand the host name");
        exit(1);
    }

    hostname = argv[1];

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = PF_INET;
    dest.sin_port = ntohs(0);
    dest.sin_addr = *(struct in_addr*)host->h_addr_list[0];

    if((sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("raw socket created error");
        exit(1);
    }

    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));

    setuid(getuid());
    pid=getpid();

    set_sighandler();
    printf("Ping %s(%s): %d bytes data in ICMP packets.\n",
          argv[1], inet_ntoa(dest.sin_addr), datalen);

    if((setitimer(ITIMER_REAL, &val_alarm, NULL)) == -1)
        bail("setitimer fails.");
    recv_reply();

    return 0;
}


void recv_reply()
{
    int n, len;
    int errno;

    n=nrecv=0;
    len=sizeof(from);

    while(nrecv < 4)
    {
        if((n=recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *)&from, &len)) < 0)
        {
            if(errno == EINTR)
                continue;
            bail("recvfrom error");
        }

        gettimeofday(&recvtime, NULL);

        if(handle_pkt())
            continue;

        nrecv++;
    }

    get_statistics(nsent, nrecv);
}


void send_ping()
{
    struct iphdr *ip_hdr;
    struct ICMPhdr *icmp_hdr;
    int len;
    int len1;

    ip_hdr = (struct iphdr *)sendbuf;
    ip_hdr->hlen = sizeof(struct iphdr)>>2;
    ip_hdr->ver = IPVERSION;
    ip_hdr->tos = 0;
    ip_hdr->tot_len = IP_HSIZE+ICMP_HSIZE+datalen;
    ip_hdr->id = 0;
    ip_hdr->frag_off = 0;
    ip_hdr->protocol = IPPROTO_ICMP;
    ip_hdr->ttl = 255;
    ip_hdr->daddr = dest.sin_addr.s_addr;
    len1 = (ip_hdr->hlen) << 2;

    icmp_hdr = (struct icmphdr *)(sendbuf + len1);
    icmp_hdr->type = 8;
    icmp_hdr->code = 0;
    icmp_hdr->icmp_id = pid;
    icmp_hdr->icmp_seq = nsent++;

    memset(icmp_hdr->data, 0xff, datalen);

    gettimeofday((struct timeval *)icmp_hdr->data, NULL);

    len = ip_hdr->tot_len;
    icmp_hdr->checksum = 0;
    icmp_hdr->checksum = checksum((u8 *)icmp_hdr, len);

    sendto(sockfd, sendbuf, len, 0, (struct sockaddr *)&dest, sizeof(dest));
}


u16 checksum(u8 *buf, int len)
{
    u32 sum = 0;
    u16 *cbuf;
    cbuf=(u16 *)buf;

    while(len > 1)
    {
        sum += *cbuf++;
        len -= 2;
    }

    if(len)
        sum += *(u8 *)cbuf;

    sum = (sum >> 16)+(sum & 0xffff);
    sum += (sum >> 16);
    
    return ~sum;
}


int handle_pkt()
{
    struct iphdr *ip;
    struct icmphdr *icmp;

    int ip_len;
    u16 ip_datalen;
    double rtt;
    struct timeval *sendtime;

    ip = (struct iphdr *)recvbuf;

    ip_hlen = (ip->hlen) << 2;
    ip_datalen = ntohs(ip->tot_len) - ip_hlen;

    icmp = (struct icmphdr *)(recvbuf + ip_hlen);

    if(checksum((u8 *)icmp, ip_datalen))
        return -1;
    
    if(icmp->icmp_id != pid)
        return -1;

    sendtime = (struct timeval*)icmp->data;
    rtt = ((&recvtime)->tv_sec - sendtime->tv_sec)*1000 + ((&recvtime)->tv_usec - sendtmie->tv_usec)/1000.0;

    printf("%d bytes from %s:icmp_seq=%u ttl=%d rtt=%.3f ms\n",
          ip_datalen,
          inet_ntoa(from.sin_addr),
          icmp->icmp_seq,
          ip->ttl,
          rtt);
    return 0;
}


void set_sighandler()
{
    act_alarm.sa_handler = alarm_handler;
    if(sigaction(SIGALRM, &act_alarm, NULL) == -1)
        bail("SIGALRM handler setting fails.");
    act_int.sa_handler = int_handler;
    if(sigaction(SIGINT, &act_alarm, NULL) == -1)
        bail("SIGALRM handler setting fails.");
}


void get_statistics(int nsent, int nrecv)
