/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void isValid(TreeNode* root, TreeNode*& prev, bool& ans) {
        if (root == NULL)
            return;
        // inorder
        isValid(root->left, prev, ans);
        if (prev == NULL)
            prev = root;
        else {
            if (root->val <= prev->val) 
                ans = false;
        }
        prev = root;
        isValid(root->right, prev, ans);
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        TreeNode* prev = NULL;
        isValid(root, prev, ans);
        return ans;
    }
};