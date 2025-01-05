#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
} node;

void inOrder(node* root)
{
    if(!root) return;
    if(root->left) inOrder(root->left);
    printf("%d->",root->val);
    if(root->right) inOrder(root->right);
}

node* insertBST(node* root, int val)
{
    node* newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;

    if(!root) return newNode;
    else
    {
        if(val < root->val) root->left = insertBST(root->left, val);
        else if(val > root->val) root->right = insertBST(root->right, val);
    }
    return root;
}

node* deleteBST(node* root, int val)
{
    if(!root) return NULL;
    if(val < root->val) root->left = deleteBST(root->left, val);
    else if(val > root->val) root->right = deleteBST(root->right, val);
    else
    {
        if(!root->left)
        {
            node* tmp = root->right;
            free(root);
            return tmp;
        }
        else if(!root->right)
        {
            node* tmp = root->left;
            free(root);
            return tmp;
        }
        else
        {
            node* ptr = root->right;
            while(ptr->left) ptr = ptr->left;
            root->val = ptr->val;
            free(ptr);
        }
    }
    return root;
}

node* find(node* root , int val)
{
    if(!root) return NULL;

    if(val < root->val) return find(root->left, val);
    else if(val > root->val) return find(root->right, val);
    else return root;
}

int main()
{
    node* root = NULL;
    int data[] = {10, 20, 5, 8, 30, 15, 3, 18, 2, 1};
    int Fdata[] = {10, 0, 50, 2};
    int ndata = sizeof(data)/sizeof(int);
    int nFdata = sizeof(Fdata)/sizeof(int);
    node* ptr;

    for(int i = 0; i < ndata; i++) root = insertBST(root, data[i]);
    inOrder(root);
    printf("\r\n");
    root = deleteBST(root, 15);
    root = deleteBST(root, 35);
    inOrder(root);
    printf("\r\n");

    for(int i = 0; i < nFdata; i++)
    {
        ptr = find(root, Fdata[i]);
        if(ptr) printf("Found: %d in %x\r\n", Fdata[i], ptr);
        else printf("Not found: %d\r\n", Fdata[i]);
    }
    
    printf("hello world\r\n");
}