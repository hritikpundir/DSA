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
    void recover(TreeNode* root, TreeNode*& prev, int& error, TreeNode*& e1f,
                 TreeNode*& e1s, TreeNode*& e2f, TreeNode*& e2s) {
        if (root == NULL)
            return;
        // left child
        recover(root->left, prev, error, e1f, e1s, e2f, e2s);

        if (prev == NULL)
            prev = root;
        else {
            if (prev->val >= root->val) {
                if (error == 0) {

                    e1f = prev;
                    e1s = root;
                } else {
                    e2f = prev;
                    e2s = root;
                }
                error++;
            }
        }
        prev = root;

        // right child
        recover(root->right, prev, error, e1f, e1s, e2f, e2s);
        return;
    }


    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        int error = 0;
        TreeNode* e1f = NULL;
        TreeNode* e1s = NULL;
        TreeNode* e2f = NULL;
        TreeNode* e2s = NULL;

        recover(root, prev, error, e1f, e1s, e2f, e2s);

        if (error == 1) {
            swap(e1f->val, e1s->val);
        } else {
            swap(e1f->val, e2s->val);
        }
        return;
    }
};