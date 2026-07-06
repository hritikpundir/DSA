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
    long long countPaths(TreeNode* root, long long targetSum){
        if(root == NULL) return 0;

        long long paths = 0;

        if(root->val == targetSum){
            paths += 1;
        }
        paths += countPaths(root->left, targetSum - root->val);
        paths += countPaths(root->right, targetSum - root->val);

        return paths;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        return countPaths(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};