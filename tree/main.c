/**************************************************************************
* File  : main.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 15 Mar 2017 10:29:23 PM EDT
*************************************************************************/
#include<stdio.h>
#include"tree.h"
void main(void)
{
	tree *node1;
	tree *node2;
	tree *node3;
	tree *node4;
	tree *node5;
	tree *node6;
	tree *node7;

	initTreeNode(&node1);
	initTreeNode(&node2);
	initTreeNode(&node3);
	initTreeNode(&node4);
	initTreeNode(&node5);
	initTreeNode(&node6);
	initTreeNode(&node7);

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;
	node6->data = 6;
	node7->data = 7;

	add_lchild(&node1,node2);
	add_rchild(&node1,node3);
	add_lchild(&node2,node4);
	add_rchild(&node2,node5);
	add_lchild(&node3,node6);
	add_rchild(&node3,node7);

	printf("Now I gona traverse this tree.\n");
	preTraverse(node1);
	printf("\n");

	int depth = tree_depth(node1);
	printf("This tree's depth is %d.\n",depth);
	
	printf("Now I gona destory this tree.\n");
	destoryTree(&node1);
}
