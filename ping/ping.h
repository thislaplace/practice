#define ICMP_ECHOREPLY 0
#define ICMP_ECHO

#define BUFSIZE 1500
#define DEFAULT_LEN 56

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct icmphdr{
    u8 type;/*消息类型*/
    u8 code;/*消息代码*/
    u16 checksum;/*定义校验*/

    union{
        struct{
            u16 id;
            u16 sequence;
        }echo;
        u32 gateway;

        struct{
            u16 unsed;
            u16 mtu;
        }frag;/*pmtu实现*/
    }un;
    /*ICMP数据占位符*/
    u8 data[0];
    #define icmp_id un.echo.id
    #define icmp_seq un.echo.sequence
};

#define ICMP_HSIZE sizeof(struct icmphdr)

struct iphdr{
    u8 hlen:4, ver:4;/*定义4位首部长度，和IP版本号为IPV4*/
    u8 tos; /*8位服务类型TOS*/
    u16 tot_len; /*16位总长度*/
    u16 id;/*16位标志位*/
    u16 frag_off;/*3位标志位*/
    u8 ttl;/*八位生存周期*/
    u8 protocol;/*8位生存周期*/
    u16 check;/*8位协议*/
    u32 saddr;/*16位IP首部校验和*/
    u32 daddr;/*32位目的IP地址*/
};
 

char *hostname;
int datalen = DEFAULT_LEN;/*ICMP消息携带的数据长度*/
char sendbuf[BUFSIZE];/*发送字符串数组*/
char recvbuf[BUFSIZE];/*接收字符串数组*/
int nsent;/*发送的ICMP消息序号*/
int nrecv;/*接受的ICMP消息序号*/
pid_t pid;/*ping程序的进程PID*/
struct timeval recvtime;/*收到ICMP应答的时间戳*/
int sockfd;/*发送和接受原始套接字*/
struct sockaddr_in dest;/*被ping的主机IP*/
struct sockaddr_in from;/*发送ping应答消息的主机*/
struct sigaction act_alarm;
struct sigaction act_int;

void alarm_handler(int);/*SIGALRM 处理程序*/
void int_handler(int);/*SIGINT 处理程序*/
void set_sighandler();/*设置信号处理程序*/
void send_ping();/*发送ping消息*/
void recv_reply();/*接受ping应答*/
u16 checksum(u8 *buf, int len);/*计算校验和*/
int handle_pkt();/*ICMP应带消息处理*/
void get_statistics(int, int);/*统计ping命令的检测结果*/
cpid bail(const char *);/*错误报告*/
