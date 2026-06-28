class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = k - 1;
        int sum = 0;
        int res = INT_MIN;
        for (int i = low; i <= high; i++) {
            sum += nums[i];
        }

        while (high < n) {
            res = max(res, sum);
            low++;
            high++;

            sum = sum - nums[low - 1];
            if (high == n)
                break;
            sum += nums[high];
        }
        return (double)res / k;
    }
};