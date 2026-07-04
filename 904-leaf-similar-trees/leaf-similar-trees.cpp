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
    void leafValueSeq(TreeNode* root, vector<int>& seq){
        if(root == NULL){
            return;
        }
        leafValueSeq(root->left, seq);
        leafValueSeq(root->right, seq);
        if(root->left == NULL && root->right == NULL){  //leaf node
            seq.push_back(root->val);
        } 
        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1 ;
        leafValueSeq(root1, r1);
        vector<int> r2 ; 
        leafValueSeq(root2, r2);

        return (r1 == r2);

    }
};