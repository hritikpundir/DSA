/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flat(TreeNode* root){
        if(root == NULL) return root;
        
        //leaf node
        if(!root->left && !root->right){
            return root;
        }
        TreeNode* leftTail = flat(root->left);
        TreeNode* rightTail = flat(root->right);

        if(leftTail){
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if(rightTail){
            return rightTail;
        }
        return leftTail;
    }

    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flat(root); 
    }
};