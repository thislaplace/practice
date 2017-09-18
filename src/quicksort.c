/**************************************************************************
* File  : quicksort.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 03 May 2017 04:44:41 AM EDT
*************************************************************************/
#include<stdio.h>
void quicksort(int *a,int l,int r);
int main()
{
    int a[10]={42,323,32,231,32,54,798,34,896,67};
    int i = 0;
    for(i=0; i<10; ++i)
    printf("%8d",a[i]);
    printf("\n");
    quicksort(a,0,9);

    return 0;
}

void quicksort(int *a,int l,int r)
{
    if(l >= r)
        return;

    int tmp = a[l];
    int left = l;
    int right = r;

    while(l < r)
    {
        while((a[r] > tmp)&&(l < r))
            r--;
        
        if(l < r)
        {
            a[l] = a[r];
            l++;
        }

        while((a[l] <= tmp)&&(l < r))
            l++;

        if(l < r)
        {
            a[r] = a[l];
            r--;
        }
    }

    a[l] = tmp;

    int i = 0;
    for(i=0; i<10; ++i)
    printf("%8d",a[i]);
    printf("\n");

    quicksort(a,left,l-1);
    quicksort(a,r+1,right);
}
