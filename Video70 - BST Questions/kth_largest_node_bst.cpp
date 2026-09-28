#include <bits/stdc++.h>
/*
Node structure which is used.

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }

};

*/

int solve(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int right = solve(root->right, i, k);

    if (right != -1)
    {
        return right;
    }

    i++;
    if (i == k)
    {
        return root->data;
    }

    return solve(root->left, i, k);
}

int KthLargest(Node *root, int k)
{
    // Write your code here.
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}