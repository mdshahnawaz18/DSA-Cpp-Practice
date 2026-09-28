/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    void flatten(Node *root)
    {
        // code
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->left)
            {
                Node *pred = curr->left;
                while (pred->right)
                {
                    pred = pred->right;
                }

                pred->right = curr->right;
                curr->right = curr->left;
            }

            curr = curr->right;
        }
        curr = root;
        while (curr != NULL)
        {
            curr->left = NULL;
            curr = curr->right;
        }
    }
};