class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCnt = 0;
        int low = 0;
        int high = 0;
        int res = 0;

        for (high = 0; high < n; high++) {
            if (nums[high] == 0)
                zeroCnt++;
            while (zeroCnt > 1) {
                if (nums[low] == 0)
                    zeroCnt--;
                low++;
            }
            int len = high - low + 1;
            res = max(res, len);
        }
        return (res - 1);
    }
};