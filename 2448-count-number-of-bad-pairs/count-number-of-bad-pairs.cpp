class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long goodPairs = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            // Key insight: (nums[i] - i) is same for all "good" pairs
            goodPairs += freq[nums[i] - i];
            freq[nums[i] - i]++;
        }
        // Total pairs = n * (n - 1) / 2
        long long totalPairs = n * (n - 1) / 2;
        return totalPairs - goodPairs;
    }
};