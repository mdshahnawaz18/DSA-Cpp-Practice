/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
    void traversalLeft(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        ans.push_back(root->data);

        if (root->left)
        {
            traversalLeft(root->left, ans);
        }

        else
        {
            traversalLeft(root->right, ans);
        }
    }

    void traversalLeaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);
    }

    void traversalRight(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if (root->right)
        {
            traversalRight(root->right, ans);
        }
        else
        {
            traversalRight(root->left, ans);
        }
        ans.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);

        traversalLeft(root->left, ans);

        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);

        traversalRight(root->right, ans);

        return ans;
    }
};