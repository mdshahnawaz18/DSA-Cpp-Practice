/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void convertBSTtoDLL(TreeNode *root, TreeNode *&head)
{
    if (root == NULL)
    {
        return;
    }

    convertBSTtoDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    convertBSTtoDLL(root->left, head);
}

TreeNode *mergeDLL(TreeNode *head1, TreeNode *head2)
{
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            tail = head1;
            head1 = head1->right;
        }
        else
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
    }

    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            tail = head2;
            head2 = head2->right;
        }
        else
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    return head;
}

int countNode(TreeNode *head)
{
    TreeNode *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// Main Function
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    // Step 1 : Convert BST into Doubly Linked List
    TreeNode *head1 = NULL;
    convertBSTtoDLL(root1, head1);
    if (head1 != NULL)
    {
        head1->left = NULL;
    }

    TreeNode *head2 = NULL;
    convertBSTtoDLL(root2, head2);
    if (head2 != NULL)
    {
        head2->left = NULL;
    }

    // Step 2 : Merge two Linked List
    TreeNode *head = mergeDLL(head1, head2);

    vector<int> ans;

    TreeNode *temp = head;
    while (temp != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->right;
    }

    return ans;
}