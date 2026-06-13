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
    TreeNode* build(vector<int>& preorder, int low, int high, int& idx,
                    unordered_map<int, int>& in) {
        if (low > high)
            return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        int id = in[root->val];

        root->left = build(preorder, low, id - 1, idx, in);
        root->right = build(preorder, id + 1, high, idx, in);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in;
        int idx = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            in[inorder[i]] = i;
        }
        int low = 0;
        int high = inorder.size() - 1;
        return build(preorder, low, high, idx, in);
    }
};