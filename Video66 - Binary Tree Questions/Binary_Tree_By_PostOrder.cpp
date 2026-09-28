/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
    int positionIndex(vector<int> &inorder, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    Node *solve(vector<int> &inorder, vector<int> &postorder, int &index, int inOrderStart, int inOrderEnd, int n)
    {
        if (index < 0 || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        int element = postorder[index--];
        Node *root = new Node(element);

        int position = positionIndex(inorder, element, n);

        root->right = solve(inorder, postorder, index, position + 1, inOrderEnd, n);
        root->left = solve(inorder, postorder, index, inOrderStart, position - 1, n);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // code here
        int n = inorder.size();
        int postOrderIndex = n - 1;

        Node *ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n);

        return ans;
    }
};