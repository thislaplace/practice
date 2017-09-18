/*********************************************
 * File  : heap.c
 * Author: laplace
 * Mail  : email
 * Time  : Fri 01 Sep 2017 01:07:01 AM EDT
 ********************************************/
#include<stdio.h>
typedef struct HeapSq
{
    int *heap;
    int len;
    int MaxSize;
}Heap;


/********************************************
 * init heap
 */
void initHeap(Heap HBT, int MS)
{
    if(MS <= 0)
    {
        printf("MS should be greater than 0\n");
        exit(-1);
    }
    HBT->heap = (int *)malloc(MS*sizeof(int));

    if(!HBT->heap)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    HBT->MaxSize = MS;
    HBT->len = 0;
}


/*********************************************
 * insert a element to heap
 */
void insertHeap(Heap *b, int x)
{
    int i;
    if(b->len == b->MaxSize)
    {
        int *p;
        p = realloc(b->heap, 2*(b->MaxSize)*sizeof(int));
        if(!p)
        {
            printf("realloc failed\n");
            exit(-1);
        }
        printf("realloc %dB size\n", 2*(b->MaxSize)*sizeof(int));
        b->heap = p;
        b->MaxSize =  2*(b->MaxSize)*sizeof(int);
    }

    b->heap[b->len] = x;
    (b->len)++;
    i = b->len - 1;

    while(i != 0)
    {
        int j = (i-1)/2;
        if(x >= b->heap[j])
            break;
        b->heap[i] = b->heap[j];
        i = j;
    }
    b->heap[i] = x;
}


/*********************************************
 * main
 */
void main()
{
    int i, x;
    int a[8] = {23, 56, 40, 63, 38, 55, 10, 16};
    Heap b;
    initHeap(&b, 5);

    for(i=0; i<8; ++i)
        insertHeap(&b, a[i]);

//    while(!EmptyHeap(&b))
//    {
//        x = delHeap(&b);
//        printf("%d ", x);
//    }
//    printf("\n");
//    destoryHeap(&b);
}
