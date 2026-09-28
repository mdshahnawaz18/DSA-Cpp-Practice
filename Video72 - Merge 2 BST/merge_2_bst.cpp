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

void inOrder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

TreeNode *inOrderToBST(int s, int e, vector<int> &inMerge)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(inMerge[mid]);
    root->left = inOrderToBST(s, mid - 1, inMerge);
    root->right = inOrderToBST(mid + 1, e, inMerge);

    return root;
}

vector<int> mergeArrays(vector<int> bst1, vector<int> bst2)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans(bst1.size() + bst2.size());

    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            ans[k++] = bst1[i++];
        }
        else
        {
            ans[k++] = bst2[j++];
        }
    }

    while (i < bst1.size())
    {
        ans[k++] = bst1[i++];
    }

    while (j < bst2.size())
    {
        ans[k++] = bst2[j++];
    }
    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> bst1, bst2;
    inOrder(root1, bst1);
    inOrder(root2, bst2);

    vector<int> mergeArray = mergeArrays(bst1, bst2);
    int s = 0, e = mergeArray.size() - 1;

    return inOrderToBST(s, e, mergeArray);
}