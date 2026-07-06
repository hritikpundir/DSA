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
    int maxLength = 0;

    void maxZigZag(TreeNode* root, bool isLeft, int length){
        if(root == NULL) return;
        
        maxLength = max(maxLength, length);

        if(isLeft){
            maxZigZag(root->left, false, length+1);
            maxZigZag(root->right, true, 1);
        }
        else{
            maxZigZag(root->right, true, length+1);
            maxZigZag(root->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        bool isLeft = true;
        int length = 1;
        maxZigZag(root->left, false, length);
        maxZigZag(root->right, true, length);
        return maxLength;
    }
};