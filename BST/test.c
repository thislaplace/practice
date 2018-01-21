/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Jan 2018 06:01:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include"BST_tree.h"

int main()
{
    int a[10] = {10, 38, 26, 62, 90, 35, 50, 28, 55, 100};
    int size;
    GET_array_size(a, size);
    BST_S *bst = create_bst(a, size);
    mid_traverse(bst);
    free_bst(bst);
}
