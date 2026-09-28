#include <bits/stdc++.h>
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};
***************/

BinaryTreeNode<int> *inOrder(BinaryTreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return NULL;
    }

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);

    return root;
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    // Write your code here
    vector<int> inOrderVal;

    inOrder(root, inOrderVal);

    int i = 0, j = inOrderVal.size() - 1;

    while (i < j)
    {
        int sum = inOrderVal[i] + inOrderVal[j];

        if (sum == target)
        {
            return true;
        }

        if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}