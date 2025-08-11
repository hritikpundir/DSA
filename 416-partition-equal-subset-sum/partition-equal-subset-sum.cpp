class Solution {
    bool subsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<bool>> dp(n, vector(target+1, false));
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);
        prev[0] = curr[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int t = 1; t <= target; ++t) {
                bool nottake = prev[t];
                bool take = false;
                if (t >= nums[i])
                    take = prev[t - nums[i]];

                curr[t] = take | nottake;
            }
            prev = curr;
        }
        return prev[target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
        }

        if (totalSum % 2)
            return false;
        int target = totalSum / 2;

        return subsetSum(nums, target);
    }
};