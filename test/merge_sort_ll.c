#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

typedef struct Node
{
    struct Node *next;
    int val;
} node;

node* AddNewNode(node *root, int val)
{
    node* ptr = root;
    while(ptr && ptr->next) ptr = ptr->next;
    node *newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    if(!root) return newNode;
    else ptr->next = newNode;
    return root;
}

void printLL(node *ptr)
{
    while(ptr)
    {
        printf("%d->", ptr->val);
        ptr = ptr->next;
    }
    printf("\r\n");
}

node* merge(node* ptr1, node* ptr2)
{
    if(!ptr1) return ptr2;
    if(!ptr2) return ptr1;
    if(ptr1->val < ptr2->val)
    {
        ptr1->next = merge(ptr1->next, ptr2);
        return ptr1;
    }
    else 
    {
        ptr2->next = merge(ptr1, ptr2->next);
        return ptr2;
    }
}

node* mergeSort(node* root)
{
    if(!root || !root->next) return root;
    node* slow = root;
    node* fast = root->next;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    root = mergeSort(root);
    fast = mergeSort(fast);
    return merge(root, fast);
}

int main(void)
{
    node *ll1 = NULL;
    node *ll2 = NULL;
    unsigned int seed = time(0);
    for(int i = 0; i < SIZE ; i++) ll1 = AddNewNode(ll1, rand_r(&seed) % SIZE);
    for(int i = 0; i < SIZE ; i++) ll2 = AddNewNode(ll2, rand_r(&seed) % SIZE);
    printf("Before:\r\n");
    printLL(ll1);
    printLL(ll2);
    ll1 = mergeSort(ll1);
    ll2 = mergeSort(ll2);
    ll1 = merge(ll1, ll2);
    printf("After:\r\n");
    printLL(ll1);
    printf("Hello world\r\n");
}