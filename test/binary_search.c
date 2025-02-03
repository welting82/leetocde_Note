#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 100

int binary_search(int num[], int len, int tgt)
{
    int r = len, l = 0, mid;

    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(num[mid] == tgt) return mid;
        else if(num[mid] > tgt) r = mid - 1;
        else if(num[mid] < tgt) l = mid + 1;
    }
    return INT_MIN;
}

int main()
{
    int vec[SIZE] = {0};
    int val[] = {100, 129, 153, 68, 150, 2, 300};
    int num;
    for(int i = 0; i < SIZE; i++) vec[i] = i + 100;

    for(int i = 0; i < sizeof(val) / sizeof(int); i++)
    {
        if((num = binary_search(vec, SIZE, val[i])) != INT_MIN) printf("{ %d, %d }\r\n", val[i], num);
        else printf("{ %d, N/A }\r\n", val[i]);
    }

    printf("hello world!\r\n");
}