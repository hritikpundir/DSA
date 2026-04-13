class Solution {
public:
    void fun(vector<int>& nums, int n, int idx, vector<vector<int>>& res){
        if(idx==n){
            res.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            swap(nums[idx],nums[i]);
            fun(nums,n,idx+1,res);
            swap(nums[idx],nums[i]);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        fun(nums, n, 0, res);
        return res;
    }
};