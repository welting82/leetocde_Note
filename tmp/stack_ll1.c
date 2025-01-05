#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


typedef struct Node
{
    int val;
    struct Node* next;
    struct Node* pre;
} Node;

typedef struct stack
{
    int size;
    Node* ptr;
} stack;

void push(stack* st, int val)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->pre = st->ptr;

    st->ptr->next = newNode;
    st->ptr = newNode;
    st->size++;
    return;
}

bool pop(stack* st, int* val)
{
    if(st->size == 0)
    {
        *val = INT_MIN;
        return false;
    }
    *val = st->ptr->val;
    st->ptr = st->ptr->pre;
    free(st->ptr->next);
    st->size--;
    return true;
}

int main()
{
    stack* st;
    int num = -1;
    st->size = 0;
    st->ptr = malloc(sizeof(Node));
    st->ptr->pre = NULL;
    st->ptr->val = 0;
    
    int res = pop(st, &num);
    printf("BBB res = %x, num = %d\r\n", res, num);

    for(int i = 0; i < 10; i++) push(st, i);

    for(int i = 0; i < 12; i++)
    {
        res = pop(st, &num);
        printf("res = %x, num = %d\r\n", res, num);
    }

    printf("hello world!\r\n");
}