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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;

        queue<pair<int, TreeNode*>> q;
        q.push({0,root});

        while(!q.empty()){
            int levelSize = q.size();
            int i = levelSize;
            double sum = 0;
            while(i--){
                pair<int, TreeNode*> p = q.front();
                q.pop();
                int level = p.first;
                TreeNode* node = p.second;

                if(node->left) q.push({level+1, node->left});
                if(node->right) q.push({level+1, node->right});

                sum += node->val;
            }
            double avg = sum / levelSize;
            res.push_back(avg);
        }
        return res;
    }
};