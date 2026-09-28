/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node *node)
    {
        if (node == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if (node->left == NULL && node->right == NULL)
        {
            pair<bool, int> p = make_pair(true, node->data);
            return p;
        }

        pair<bool, int> leftAns = isSumTreeFast(node->left);
        pair<bool, int> rightAns = isSumTreeFast(node->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        int leftSum = leftAns.second;
        int rightSum = rightAns.second;

        bool check = node->data == leftSum + rightSum;

        pair<bool, int> ans;

        if (isLeftSumTree && isRightSumTree && check)
        {
            ans.first = true;
            ans.second = node->data + leftSum + rightSum;
        }
        else
        {
            ans.second = false;
        }

        return ans;
    }

    bool isSumTree(Node *node)
    {
        // code here
        return isSumTreeFast(node).first;
    }
};