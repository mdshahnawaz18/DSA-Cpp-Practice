/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    int height(Node* root){
        if(root == NULL){
            return -1;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left , right) + 1;
        
        return ans;
    }
    
  public:
    bool isBalanced(Node* root) {
        if(root == NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root -> right)) <= 1;
        
        if(left & right & diff){
            return true;
        }
        else{
            return false;
        }
        
    }
};