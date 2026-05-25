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
    void fun(TreeNode* root, int& res, int pSum) {
        if (root == NULL)
            return;
        pSum = pSum * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            res += pSum;
            return;
        }
        fun(root->left, res, pSum);
        fun(root->right, res, pSum);
    }

    int sumNumbers(TreeNode* root) {
        int pSum = 0;
        int res = 0;
        fun(root, res, pSum);
        return res;
    }
};