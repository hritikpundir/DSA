class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // variable window
        int n = nums.size();
        int low = 0;
        int res = 0;
        int zeroCount = 0;

        for (int high = 0; high < n; high++) {
            if (nums[high] == 0)
                zeroCount++;

            while (zeroCount > k) { // wrong case
                if (nums[low] == 0)
                    zeroCount--;
                low++;
            }
            int len = high - low +1;
            res = max(res, len);
        }
        return res;
    }
};