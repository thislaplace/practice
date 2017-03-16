/**************************************************************************
* File  : tree.c
* Author: yuhao
* Mail  : yu.hao@utt.com.cn
* Time  : Wed 15 Mar 2017 09:48:35 PM EDT
*************************************************************************/
#include<stdio.h>
#include"tree.h"
void initTree(tree **t)
{
	*t = NULL;
	if(*t != NULL)
	{
		printf("init failed\n");
	}else{
		printf("init successed\n");
	}
	return;
}

void createTree(tree **t)
{
	tree *tmp = *t;
	tmp->data = 0;
	tmp->lchild = NULL;
	tmp->rchild = NULL;
	if(tmp != NULL)printf("success create a tree\n");
	else printf("fail to create a tree\n");
	return;
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
	if(NULL == t)
	{
		return;
	}
	tree *tmp = t;
	int l=0,r=0;
	if(tmp->lchild != NULL)
	{
		l = tree_depth(tmp->lchild);
	}else{
		l = l + 1;
	}
	if(tmp->rchild != NULL)
	{
		r = tree_depth(tmp->rchild);
	}else{
		r = r + 1;
	}
	return l > r ? l : r;
}


