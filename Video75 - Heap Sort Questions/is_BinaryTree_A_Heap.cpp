/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

int countNodes(Node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
    return ans;
}

bool isBST(Node *tree, int i, int n)
{
    if (tree == NULL)
    {
        return true;
    }
    if (i >= n)
    {
        return false;
    }

    else
    {
        bool left = isBST(tree->left, 2 * i + 1, n);
        bool right = isBST(tree->right, 2 * i + 2, n);
        return left && right;
    }
}

bool isMAX(Node *tree)
{
    if (tree->left == NULL && tree->right == NULL)
    {
        return true;
    }
    if (tree->left != NULL && tree->right == NULL)
    {
        return tree->data > tree->left->data;
    }

    else
    {
        bool left = isMAX(tree->left);
        bool right = isMAX(tree->right);

        return left &&
               right &&
               (tree->data > tree->left->data) &&
               (tree->data > tree->right->data);
    }
}

class Solution
{
public:
    bool isHeap(Node *tree)
    {
        // code here
        int index = 0;
        int n = countNodes(tree);

        if (isBST(tree, index, n) && isMAX(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};