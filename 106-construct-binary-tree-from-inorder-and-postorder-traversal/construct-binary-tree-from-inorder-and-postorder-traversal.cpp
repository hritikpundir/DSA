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
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& in,
                    int low, int high, int& postIdx) {
        if (low > high)
            return NULL;
        TreeNode* node = new TreeNode(postorder[postIdx]);
        int inIdx = in[node->val];
        postIdx--;

        node->right = build(postorder, in, inIdx + 1, high, postIdx);
        node->left = build(postorder, in, low, inIdx - 1, postIdx);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in;
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        int postIdx = postorder.size() - 1; // last element
        int low = 0;
        int high = inorder.size() - 1;
        return build(postorder, in, low, high, postIdx);
    }
};