/*************************************************************************
	> File Name: BST_tree.h
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Jan 2018 10:08:03 PM CST
 ************************************************************************/

#ifndef _BST_TREE_H
#define _BST_TREE_H

#define TRUE 1
#define FALSE 0 

typedef void VOID;
typedef unsigned int UINT;
typedef int BOOL_t;
typedef int INT;
typedef double DOUBLE;

typedef enum err{
    ERR_SUCCESS = 1,
    ERR_MALLOC,
    ERR_NULL
}ERR_CODE_E;

#define GET_array_size(a, size) { \
    size  = sizeof(a) / sizeof(a[0]);\
}


typedef struct bst{
    struct bst *pl_node;
    struct bst *pr_node;
    INT iElement;
}BST_S;


BST_S* create_bst(INT *a, INT iLen);
BST_S* create_node(INT iElement);
BOOL_t add_lchild(BST_S *bst, BST_S *child);
BOOL_t add_rchild(BST_S *bst, BST_S *child);
BOOL_t free_bst(BST_S *bst);
BOOL_t mid_traverse(BST_S *bst);
#endif
