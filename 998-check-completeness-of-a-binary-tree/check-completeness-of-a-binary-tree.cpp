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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            int levelNodes = q.size();
            while (levelNodes--) {
                TreeNode* t = q.front();
                q.pop();
                if (t == NULL) {
                    nullSeen = true;
                } else {
                    if (nullSeen) {
                        return false;
                    }

                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        return true;
    }
};