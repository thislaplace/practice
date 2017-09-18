/**************************************************************************
* File  : tree.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 15 Mar 2017 09:48:35 PM EDT
*************************************************************************/
#include<stdio.h>
#include"tree.h"

void initTreeNode(tree **t)
{
	*t = (tree*)malloc(sizeof(tree));
	(*t)->data = 0;
	(*t)->lchild = NULL;
	(*t)->rchild = NULL;
	if((*t) != NULL)printf("success to init a node\n");
	else printf("fail to init a node\n");
	return;
}

void destoryTree(tree **t)
{
	if(NULL == *t)
		return;
	if((*t)->lchild != NULL)
		destoryTree(&((*t)->lchild));
	if((*t)->rchild != NULL)
		destoryTree(&((*t)->rchild));
	free(*t);
	*t = NULL;
	printf("success to destory a treeNode\n");
}

void add_lchild(tree **t, tree *lchild)
{
	if(NULL == *t)
	{
		return;
	}
	tree *tmp = *t;
	tmp->lchild = lchild;
}

void add_rchild(tree **t, tree *rchild)
{
	if(NULL == *t)
	{
		return;
	}
	tree *tmp = *t;
	tmp->rchild = rchild;
}

int tree_depth(tree *t)
{
	int l=0,r=0;
	if(t == NULL)
	{
		return 0;
	}
	l = tree_depth(t->lchild) + 1;
	r = tree_depth(t->rchild) + 1;

	return l>r?l:r;
}

void preTraverse(tree *t)
{
	if(t == NULL)
		return;
	printf("%d ",t->data);
	preTraverse(t->lchild);
	preTraverse(t->rchild);
}
