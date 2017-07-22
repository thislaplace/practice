/**************************************************************************
* File  : test.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Thu 13 Jul 2017 04:50:12 PM CST
*************************************************************************/
#include <stdint.h>
#include<stdio.h>

#define IH_NMLEN 32
#define SWVER_1 8
#define SWVER_2 8
#define SWVER_3 8
#define HWVER_1 4
#define HWVER_2 4


typedef struct image_header {
	unsigned int ih_magic;	/* Image Header Magic Number	*/
	unsigned int ih_hcrc;	/* Image Header CRC Checksum	*/
	unsigned int ih_time;	/* Image Creation Timestamp	*/
	unsigned int ih_size;	/* Image Data Size		*/
	unsigned int ih_load;	/* Data	 Load  Address		*/
	unsigned int ih_ep;		/* Entry Point Address		*/
	unsigned int ih_dcrc;	/* Image Data CRC Checksum	*/
	unsigned char ih_os;		/* Operating System		*/
	unsigned char ih_arch;	/* CPU architecture		*/
	unsigned char ih_type;	/* Image Type			*/
	unsigned char ih_comp;	/* Compression Type		*/
	unsigned char ih_name[IH_NMLEN];	/* Image Name		*/
} image_header_t;


int get_verinfo_from_file(char *file,int *hwVer,int *swVer);
int main()
{
    char *file = "./openwrt-ar71xx-generic-ap147-8M-squashfs-sysupgrade.bin";
    int hwVer = 0;
    int swVer = 0;
    get_verinfo_from_file(file,&hwVer,swVer);
//    printf("hwVer = %d, swVer = %d\n",hwVer,swVer);
    return ;
}

/*获取软硬件版本信息*/

int get_verinfo_from_file(char *file,int *hwVer,int *swVer)
{
    FILE *fp;
    image_header_t head;

    if(fp = fopen(file, "r"))
    {
        fread(&head, 1, sizeof(image_header_t), fp);
//  printf("the size of imageheader is %s\n",sizeof(image_header_t));

        fclose(fp);
    }
    printf("%d",head.ih_size);

    return;
}
