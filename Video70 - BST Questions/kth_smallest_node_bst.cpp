/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/

int solve(TreeNode<int> *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    i++;
    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    //  Write the code here.
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}