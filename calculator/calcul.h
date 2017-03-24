#define DATA_STACK_SIZE 128
#define OPERATOR_STACK_SIZE 64
#define _CALCUL_H
typedef struct dataStack{
    int data[DATA_STACK_SIZE];
    int top;
}dataStack;

typedef struct operatorStack{
    char str[OPERATOR_STACK_SIZE];
    int top;
}operatorStack;

