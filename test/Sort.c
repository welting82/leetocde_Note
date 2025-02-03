#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE 10

void swap(int* a, int * b)
{
    if(*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

void bubble_sort(int* nums, int len)
{
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 1; i < len; i++)
        {
            if(nums[i] < nums[i - 1])
            {
                swap(&nums[i], &nums[i - 1]);
                flag = true;
            }
        }
    }
}

void select_sort(int* nums, int len)
{
    int _min;
    for(int idx = 0; idx < len; idx++)
    {
        _min = idx;
        for(int i = idx + 1; i < len; i++)
        {
            if(nums[i] < nums[_min]) _min = i;
        }
        swap(&nums[idx], &nums[_min]);
    }
}

void insert_sort(int* nums, int len)
{
    int idx;
    for(int i = 0; i < len; i++)
    {
        idx = i - 1;
        while(idx > -1 && nums[idx] > nums[i]) idx--;
        for(int j = idx + 1; j < i; j++) swap(&nums[j], &nums[i]);
    }
}

void mergeHelper(int* nums, int* res, int l, int r)
{
    if(l >= r) return;
    int mid = (r + l) / 2, idx_l, idx_r;
    mergeHelper(nums, res, l, mid);
    mergeHelper(nums, res, mid + 1, r);
    idx_l = l, idx_r = mid + 1;
    for(int i = l; i <= r; i++)
    {
        if(idx_l > mid) res[i] = nums[idx_r++];
        else if(idx_r > r) res[i] = nums[idx_l++];
        else if(nums[idx_l] <= nums[idx_r]) res[i] = nums[idx_l++];
        else if(nums[idx_l] > nums[idx_r]) res[i] = nums[idx_r++];
    }
    for(int i = l; i <= r; i++) *(nums + i) = *(res + i);
}

void merge_sort(int* nums, int len)
{
    int* res = malloc(len * sizeof(int));
    mergeHelper(nums, res, 0, len - 1);
    free(res);
}

void quickHelper(int* nums, int l ,int r)
{
    if(l > r) return;
    int p = r, i = l, j = r;
    while(i < j)
    {
        while(i < r && nums[i] <= nums[p]) i++;
        while(j > l && nums[j] >= nums[p]) j--;
        if(i < j) swap(&nums[i], &nums[j]);
    }
    if(nums[i] > nums[p]) swap(&nums[i], &nums[p]);
    quickHelper(nums, l, i - 1);
    quickHelper(nums, i + 1, r);
    return;
}

void quick_sort(int* nums, int len)
{
    quickHelper(nums, 0 ,len - 1);
}

int main()
{
    printf("===main start===\r\n");
    int nums[SIZE] = {3,5,6,4,1,2,7,8,2,10};
    char str[10];
    while(1)
    {
        printf("Select Algo. type: ");
        scanf("%s", str);
        if(str[0] == '1') bubble_sort(nums, sizeof(nums) / sizeof(nums[0]));
        else if(str[0] == '2') select_sort(nums, sizeof(nums) / sizeof(nums[0]));
        else if(str[0] == '3') insert_sort(nums, sizeof(nums) / sizeof(nums[0]));
        else if(str[0] == '4') merge_sort(nums, sizeof(nums) / sizeof(nums[0]));
        else if(str[0] == '5') quick_sort(nums, sizeof(nums) / sizeof(nums[0]));
        else break;

        printf("Res:\r\n");
        for(int i = 0; i < SIZE; i++) printf("%d ",nums[i]);
        printf("\r\n");
    }
    printf("===main end===\r\n");
}