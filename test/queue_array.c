#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 100

typedef struct queue
{
    int vec[SIZE];
    int head;
    int tail;
} queue;

void initqueue(queue* q)
{
    q->head = q->tail = 0;
}

bool enqueue(queue* q, int val)
{
    if(q->tail == SIZE) return false;
    q->vec[q->tail] = val;
    q->tail++;
    return true;
}

int dequeue(queue* q)
{
    if(q->head >= q->tail) return INT_MIN;
    int val = q->vec[q->head];
    q->head++;
    return val;
}

int main()
{
    queue q1, q2;
    int num;
    initqueue(&q1);
    initqueue(&q2);

    printf("Before num = %d\r\n", dequeue(&q1));

    for(int i = 0; i < 10; i++) enqueue(&q1, i);
    for(int i = 20; i > -1; i--) enqueue(&q2, i);

    for(int i = 0; i <5; i++) dequeue(&q1);
    for(int i = 100; i <120; i++) enqueue(&q1, i);
    printf("Q1: \r\n");
    while((num = dequeue(&q1)) != INT_MIN) printf("%d ", num);
    printf("\r\n");

    printf("Q2: \r\n");
    while((num = dequeue(&q2)) != INT_MIN) printf("%d ", num);
    printf("\r\n");

    printf("hello world!\r\n");
}