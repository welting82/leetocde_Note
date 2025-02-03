#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 100

typedef struct stack
{
    int vec[SIZE];
    int idx;
} stack;

bool push(stack* st, int val)
{
    if(st->idx == SIZE) return false;
    st->vec[st->idx] = val;
    st->idx++;
    return true;
}

int pop(stack* st)
{
    if(st->idx == 0) return INT_MIN;
    st->idx--;
    return st->vec[st->idx];
}

int main()
{
    stack st1, st2;
    st1.idx = st2.idx = 0;
    int num;
    printf("Before num = %d\r\n", pop(&st1));

    for(int i = 0; i < 10; i++) push(&st1, i);
    for(int i = 20; i > -1; i--) push(&st2, i);

    for(int i = 0; i < 5; i++) printf("St1, Round:%d, num = %d\r\n", i, pop(&st1));
    for(int i = 100; i < 120; i++) push(&st1, i);

    printf("St1: \r\n");
    while((num = pop(&st1)) != INT_MIN) printf("%d ", num);
    printf("\r\n");

    printf("St2: \r\n");
    while((num = pop(&st2)) != INT_MIN) printf("%d ", num);
    printf("\r\n");

    printf("hello world!\r\n");
}