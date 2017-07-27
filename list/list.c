/**************************************************************************
 * * File  : list.c
 * * Author: yuhao
 * * Mail  : yu.hao@utt.com.cn
 * * Time  : Thu 16 Mar 2017 06:18:37 PM CST
 * *************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void  add(student *s , int num , char * name){
	if(s==NULL)
		return;
	student *newStudent;
	while(s->next != NULL)
		s = s->next;

	newStudent = (student*)malloc(sizeof(student));
	newStudent->num = num;
	newStudent->name = name;
	newStudent->next = NULL;
    s->next = newStudent;

    return;
}

void destory(student **s)
{
    student *tmp;
    if((*s) != NULL)
    {
        tmp = *s;
        free(*s);
        *s = NULL;
        destory(&((tmp)->next));
    }else{
        return;
    }
}

void studentPrintf(student *s)
{
	if(s == NULL)
		return;

	student *tmp = s;
	
	while(tmp->next != NULL){
		printf("%d , %s\n",tmp->num,tmp->name);
		tmp=tmp->next;
	}
	printf("%d , %s\n",tmp->num,tmp->name);
	printf("------------------------------------------------------------\n");
}


void sortStudent(student *s){

	if(s == NULL)
		return;

	student *pre;
	student *tmp;
	student *tmpNext;
	int i = n;
	int j;

	for(i=1;i<n;++i){

		pre = s;
		tmp = pre->next;
		tmpNext = tmp->next;

		for(j=i;j<n;++j){
			if((tmp->num) > (tmpNext->num)){
				tmp->next = tmpNext->next;
				pre->next = tmpNext;
				tmpNext->next = tmp;
				pre = tmpNext;
				tmpNext = tmp->next;
			}else{
				pre = tmp;
				tmp = tmpNext;
				tmpNext = tmpNext->next;
			}
		}
	}
}

void deletOddStu(student *s){
	if(s == NULL)
		return;
	student *tmp = s;
	student *pre = s;
	while(tmp != NULL){
		if((tmp->num)%2 == 0){
			pre = tmp;
			tmp = tmp->next;
		}else{
			pre->next = tmp->next;
			tmp = pre->next;
		}
	}
}




void main(void){


	char *a1 = "Name1";
	char *a2 = "Name2";
	char *a3 = "Name3";
	char *a4 = "Name4";
	char *a5 = "Name5";
	char *a6 = "Name6";
	char *head = "head";
	student s;


	s.num = 0;
	s.name =head;
	s.next = NULL;
	add(&s,5,a1);
	add(&s,4,a2);
    add(&s,1,a3);
	add(&s,3,a4);
    add(&s,6,a5);
	add(&s,2,a6);
	studentPrintf(&s);

	sortStudent(&s);
	studentPrintf(&s);

	deletOddStu(&s);
	studentPrintf(&s);
    destory(&(s.next));
}
