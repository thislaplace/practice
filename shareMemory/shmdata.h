#ifndef _SHMDATA_H_
#define _SHMDATA_H_
#define TEXT_SIZE 128
typedef struct shmdata {
    int written;
    char text[TEXT_SIZE];
}shmdata;
#endif
