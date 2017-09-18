/*********************************************
 * File  : hash.c
 * Author: laplace
 * Mail  : email
 * Time  : Wed 30 Aug 2017 10:35:53 PM EDT
 ********************************************/
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}NODE;

typedef struct HASH_TABLE
{
    NODE *value[10];
}HASH_TABLE;


/*******************************
 * key
 */
int getKey(int data)
{
    return data%10;
}

/*******************************
 * create a hash table
 */
HASH_TABLE * createHash()
{
    HASH_TABLE *pHashTb = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
    memset(pHashTb, 0x0, sizeof(HASH_TABLE));
    return pHashTb;
}


/******************************
 * insert element to hash table
 */
void insertElement(HASH_TABLE *HTable, int data)
{
    if(HTable == NULL)
        return;

    int key = getKey(data);
    NODE *tmpNODE = (NODE*)malloc(sizeof(NODE));
    NODE *pNODE = (NODE*)malloc(sizeof(NODE));
    pNODE->data = data;
    pNODE->next = NULL;

    if(HTable->value[key] == NULL)
        HTable->value[key] = pNODE;
    else
    {
        tmpNODE = HTable->value[key];
        while(tmpNODE->next != NULL)
            tmpNODE = tmpNODE->next;
        tmpNODE->next = pNODE;
    }
}


/*******************************
 * del a element from the table
 */
void delNode(HASH_TABLE *table, int data)
{
    int key = getKey(data);
    int flags = 0;
    NODE *tmp = NULL;
    NODE *tmpNext = NULL;
    if(table->value[key] == NULL)
        goto out;
    tmp = table->value[key];
    tmpNext = tmp->next;
    if(tmp->data == data)
    {
        free(tmp);
        tmp = NULL;
        table->value[key] = tmpNext;
        flags = 1;
    }
    else
    {
        while(tmpNext != NULL)
        {
            if(tmpNext->data == data)
            {
                tmp->next = tmpNext->next;
                tmpNext->next = NULL;
                free(tmpNext);
                tmpNext = NULL;
                flags = 1;
                break;
            }
            tmpNext = tmpNext->next;
        }
    }
    out:
    if(flags == 1)
        printf("del ok\n");
    else
        printf("no such node\n");
    return;
}


/*******************************
 * traversal table
 */
void traversalTable(HASH_TABLE *table)
{
    int i = 0;
    while(i < 10)
    {
        if(table->value[i] != NULL)
        {
            NODE *tmp = table->value[i];
            while(tmp != NULL)
            {
                printf("data = %d ", tmp->data);
                tmp = tmp->next;
            }
            printf("\n");
        }
        i++;
    }
}


/*********************************
 * destory Hash Table
 */
void destoryTable(HASH_TABLE **table)
{
    int i = 0;
    NODE *tmp = NULL;
    NODE *tmpNext = NULL;
    while(i < 10)
    {
        if((*table)->value[i] != NULL)
        {
            tmp = (*table)->value[i];
            while(tmp != NULL)
            {
                tmpNext = tmp->next;
                free(tmp);
                tmp = tmpNext;
            }
            (*table)->value[i] = NULL;
        }
        ++i;
    }
    free(*table);
    *table = NULL;
    return;
}


/*********************************
 * main
 */
int main()
{
    HASH_TABLE *table = createHash();
    insertElement(table, 13);
    insertElement(table, 12);
    insertElement(table, 14);
    insertElement(table, 15);
    insertElement(table, 55);
    insertElement(table, 16);
    insertElement(table, 17);
    insertElement(table, 7);
    insertElement(table, 18);
    insertElement(table, 19);
    insertElement(table, 9);
    insertElement(table, 29);
    insertElement(table, 100);
    traversalTable(table);
    delNode(table, 19);
    traversalTable(table);
    destoryTable(&table);
}
