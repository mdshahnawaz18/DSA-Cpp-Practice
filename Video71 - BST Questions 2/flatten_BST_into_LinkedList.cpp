#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inOrder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    // Write your code here
    vector<int> inOrderVal;
    inOrder(root, inOrderVal);

    int n = inOrderVal.size();

    TreeNode<int> *newRoot = new TreeNode<int>(inOrderVal[0]);
    TreeNode<int> *curr = newRoot;

    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inOrderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
