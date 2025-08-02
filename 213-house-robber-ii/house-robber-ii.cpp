class Solution {
    int func(int n1, int n2, vector<int>& nums) {
        int prev, prev2;
        prev = prev2 = 0;

        for (int i = n1; i < n2; ++i) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int notTake = 0 + prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[n-1];
        int ans1 = func(0, n - 1, nums);
        int ans2 = func(1, n, nums);
        return max(ans1, ans2);
    }
};