#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define SIZE 20

void swap(int* a, int* b)
{
    if(*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

void printArray(int* num, int len)
{
    for(int i = 0; i < len ; i++) printf("%d ", num[i]);
    printf("\r\n");
    printf("\r\n");
}

void quick_qort(int* num, int l, int r)
{
    if(l == r) return;
    int p = r - 1, pos = l;
    for(int i = l; i < r - 1; i++)
    {
        if(num[i] < num[p]) swap(&num[i], &num[pos++]);
    }
    swap(&num[pos], &num[p]);
    quick_qort(num, l, pos);
    quick_qort(num, pos + 1, r);
}

int main()
{
    int num[SIZE] = {0};
    unsigned int seed = time(0);
    for(int i = 0; i < SIZE ; i++) num[i] = rand_r(&seed) % SIZE;
    printf("Origin: ");
    printArray(num, SIZE);
    quick_qort(num, 0, SIZE);
    printf("Sorted: ");
    printArray(num, SIZE);

    printf("hello world!\r\n");
}