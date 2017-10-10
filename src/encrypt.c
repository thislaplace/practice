#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 0x8899

typedef enum RETVALUE
{
    OPEN=1,CLOSE=2
}RETVALUE;

int key = 0;


static void usage(void)
{
    printf("usage:\n\tencrypt open/close filename\n");
    exit(-1);
}


int arg_check(int num, char *str)
{
    printf("%s\n", str);
    if(num < 3)
    {
	goto failed;
    }

    if(strcmp("close", str) == 0)
    {
	return CLOSE;
    }
    else if(strcmp("open", str) == 0)
    {
	return OPEN;
    }
    else
    {
	goto failed;
    }

failed:
    usage();
}


int operate(char *str)
{
    char cmd[64];
    int c;
    FILE *fp = fopen(str, "r");
    FILE *tmp = fopen("/tmp/tmp", "w+");

    if(fp == NULL || tmp == NULL)
	usage();

    if(key > 0)
	fputs("The file has been encrypted, you may contact Mr.y.\n", tmp);
    else if(key < 0)
	while((c = fgetc(fp)) != '\n');

    while((c = fgetc(fp)) != EOF)
	fputc(c+key, tmp);

    fclose(fp);
    fclose(tmp);

    bzero(cmd, sizeof(cmd));
    sprintf(cmd, "rm -f %s", str);
    system(cmd);

    bzero(cmd, sizeof(cmd));
    sprintf(cmd, "mv -f /tmp/tmp %s", str);
    system(cmd);
}


int main(int argc, char **argv)
{
    RETVALUE ret = arg_check(argc, *(argv+1));

    switch(ret)
    {
	case CLOSE:
            key = KEY;
	    break;
	case OPEN:
            key = 0 - KEY;
	    break;
        default:
	    usage();
	    break;
    }

    operate(*(argv+2));

    return 0;
}
