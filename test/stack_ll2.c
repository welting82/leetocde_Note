#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


typedef struct Node
{
    int val;
    struct Node* next;
} Node;

void push(Node** st, int val)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = *st;
    *st = newNode;
    return;
}

int pop(Node** st)
{
    if(!*st) return INT_MIN;
    Node* tmp = *st;
    int val = tmp->val;
    *st = (*st)->next;
    free(tmp);
    return val;
}

int main()
{
    Node* st1 = NULL;
    Node* st2 = NULL;

    printf("Before num = %d\r\n", pop(&st1));

    for(int i = 0; i < 10; i++) push(&st1, i);
    for(int i = 20; i > -1; i--) push(&st2, i);

    for(int i = 0; i < 12; i++) printf("St1, Round:%d, num = %d\r\n", i, pop(&st1));
    for(int i = 0; i < 20; i++) printf("St2, Round:%d, num = %d\r\n", i, pop(&st2));

    printf("hello world!\r\n");
}