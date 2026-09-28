#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }

    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}


Node* minValue(Node *root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;

}

Node* maxValue(Node *root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;

}

Node* deleteFromBST(Node* root , int val){
    if(root == NULL){
        return root;
    }

    if(root->data == val){

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left , val);
        return root;
    }
    
    else{
        root->right = deleteFromBST(root->right , val);
        return root;
    }
    return root;

}


int main()
{
    Node *root = NULL;

    cout << "Enter Input : " << endl;
    takeInput(root);

    cout << "Printing the BST : " << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Preorder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    postOrder(root);
    cout << endl;

    cout<<"Min Value is "<<minValue(root)->data<<endl;
    cout<<"Max Value is "<<maxValue(root)->data<<endl;

    root = deleteFromBST(root , 40);

    cout << "Printing the BST : " << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Preorder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}