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
    int a[4]={4,3,2,1};
    int i = 0;

    quicksort(a,0,3);

    for(i=0; i<4; ++i)
    printf("%8d",a[i]);
    printf("\n");

    return 0;
}

void quicksort(int *a,int l,int r)
{
    if(l == r)
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
            a[l++] = a[r];
        }

        while((a[l] <= tmp)&&(l < r))
            l++;

        if(l < r)
        {
            a[r--] = a[l];
        }
    }

    a[l] = tmp;

    quicksort(a,left,l-1);
    quicksort(a,r+1,right);
}
