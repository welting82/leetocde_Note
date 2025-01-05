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

void merge_sort(int* num, int l, int r)
{
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    int tmp[r - l + 1];
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);

    int j = l, k = mid + 1;
    for(int i = l; i <= r; i++)
    {
        if(k > r) tmp[i - l] = num[j++];
        else if(j > mid) tmp[i - l] = num[k++];
        else if(num[j] <= num[k]) tmp[i - l] = num[j++];
        else tmp[i - l] = num[k++];
    }
    for(int i = 0; i <= r - l; i++) num[i + l] = tmp[i];
}

int main()
{
    int num[SIZE] = {0};
    unsigned int seed = time(0);
    for(int i = 0; i < SIZE ; i++) num[i] = rand_r(&seed) % SIZE;
    printf("Origin: ");
    printArray(num, SIZE);
    merge_sort(num, 0, SIZE - 1);
    printf("Sorted: ");
    printArray(num, SIZE);

    printf("hello world!\r\n");
}
