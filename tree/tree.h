/***********************************************************
 *
 *
 *
 * *********************************************************/
#include<stdlib.h>
typedef struct treeNode{
	struct treeNode *lchild;
	struct treeNode *rchild;
	int data;
}tree;

void initTreeNode(tree **t);
void destoryTree(tree **t);
void add_lchild(tree **t, tree *lchild);
void add_rchild(tree **t, tree *rchild);
int tree_depth(tree *t);
void preTraverse(tree *t);
