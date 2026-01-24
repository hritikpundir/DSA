class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int minending = nums[0];
        int maxending = nums[0];
        int minAns = nums[0];
        int a2 = nums[0];

        int sumOfArray = 0;
        for (int i = 0; i < n; ++i) {    //sum of array
            sumOfArray += nums[i];
        }

        for (int i = 1; i < n; ++i) {    //minsum for edge results
            minending = min(nums[i], minending + nums[i]);
            minAns = min(minAns, minending);
        }
        int a1 = sumOfArray - minAns;

        for (int i = 1; i < n; ++i) {
            maxending = max(nums[i], maxending + nums[i]);
            a2 = max(a2, maxending);
        }
        if (a1 == 0)
            return a2;
        return max(a1, a2);
    }
};