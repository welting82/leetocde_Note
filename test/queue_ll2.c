#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


typedef struct Node
{
    int val;
    struct Node* next;
} Node;

typedef struct queue
{
    struct Node* head;
    struct Node* tail;
} queue;

void initqueue(queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue* q, int val)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if(!q->head && !q->tail)
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    return;
}

int dequeue(queue* q)
{
    if(!q->head) return INT_MIN;
    Node* tmp = q->head;
    int val = tmp->val;
    q->head = q->head->next;
    free(tmp);
    return val;
}

int main()
{
    queue q1;
    queue q2;
    initqueue(&q1);
    initqueue(&q2);

    printf("Before num = %d\r\n", dequeue(&q1));

    for(int i = 0; i < 10; i++) enqueue(&q1, i);
    for(int i = 20; i > -1; i--) enqueue(&q2, i);

    for(int i = 0; i < 12; i++) printf("q1, Round:%d, num = %d\r\n", i, dequeue(&q1));
    for(int i = 0; i < 20; i++) printf("q2, Round:%d, num = %d\r\n", i, dequeue(&q2));

    printf("hello world!\r\n");
}