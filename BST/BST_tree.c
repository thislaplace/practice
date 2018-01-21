/*************************************************************************
	> File Name: BST_tree.c
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Jan 2018 10:10:24 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "BST_tree.h"


BST_S* create_node(INT iElement)
{
    BST_S *pNode = (BST_S*)malloc(sizeof(BST_S));
    if(pNode == NULL)
    {
        return NULL;
    }

    pNode->iElement = iElement;
    pNode->pl_node = NULL;
    pNode->pr_node = NULL;

    return pNode;
}

BOOL_t add_lchild(BST_S *bst, BST_S *child)
{
    if(bst == NULL || child == NULL)
    {
        return ERR_NULL;
    }

    if(bst->pl_node == NULL)
    {
        bst->pl_node = child;
    }
    else
    {
        child->pl_node = bst->pl_node; 
        bst->pl_node = child;
    }

    printf("add left child: %d\n", child->iElement);

    return ERR_SUCCESS;
}


BOOL_t add_rchild(BST_S *bst, BST_S *child)
{
    if(bst == NULL || child == NULL)
    {
        return ERR_NULL;
    }

    if(bst->pr_node == NULL)
    {
        bst->pr_node = child;
    }
    else
    {
        child->pl_node = bst->pr_node; 
        bst->pr_node = child;
    }

    printf("add right child: %d\n", child->iElement);

    return ERR_SUCCESS;
}


BOOL_t free_bst(BST_S *bst)
{
    if (bst == NULL) 
    {
        return ERR_NULL; 
    }

    free_bst(bst->pr_node);
    free_bst(bst->pl_node);

    printf("free\n");
    free(bst);
}


BST_S* create_bst(INT *a, INT iLen)
{
    INT i;
    BST_S* pChild = NULL;
    BST_S* pBst = NULL;
    BST_S* pTmp = pBst;

    if ((pBst = create_node(a[0])) == NULL)    
    {
        return NULL;
    }

    for(i=1; i<iLen; ++i)
    {
        pTmp = pBst;
        for(;;)
        {
            if(a[i] > pTmp->iElement) 
            {
                if(pTmp->pr_node == NULL)
                {
                    printf("pTmp->pr_node == NULL\n");
                    pChild = create_node(a[i]);
                    add_rchild(pTmp, pChild);
                    break;
                }
                else
                {
                    pTmp = pTmp->pr_node;
                }
            }
            else
            {
                if(pTmp->pl_node == NULL)
                {
                    printf("pTmp->pl_node == NULL\n");
                    pChild = create_node(a[i]);
                    add_lchild(pTmp, pChild);
                    break;
                }
                else
                {
                    pTmp = pTmp->pl_node;
                }
            }
        }
    }

    return pBst;
}

BOOL_t mid_traverse(BST_S *bst)
{
    if(bst == NULL)
    {
        return ERR_NULL;
    }

    mid_traverse(bst->pl_node);
    printf("%d\n", bst->iElement);
    mid_traverse(bst->pr_node);
}
