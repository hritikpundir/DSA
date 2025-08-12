class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2,
            total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> left(nums.begin(), nums.begin() + n),
            right(nums.begin() + n, nums.end());
        vector<vector<int>> leftSums(n + 1), rightSums(n + 1);

        for (int mask = 0; mask < (1 << n); ++mask) {
            int lsum = 0, rsum = 0, lcnt = 0, rcnt = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    lsum += left[i];
                    ++lcnt;
                }
                if (mask & (1 << i)) {
                    rsum += right[i];
                    ++rcnt;
                }
            }
            leftSums[lcnt].push_back(lsum);
            rightSums[rcnt].push_back(rsum);
        }

        for (int i = 0; i <= n; ++i)
            sort(rightSums[i].begin(), rightSums[i].end());

        int res = INT_MAX;
        for (int k = 0; k <= n; ++k) {
            for (int a : leftSums[k]) {
                int target = (total / 2) - a;
                auto& vec = rightSums[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                for (int d = -1; d <= 0; ++d) {
                    auto jt = it;
                    if (d == -1 && jt != vec.begin())
                        --jt;
                    if (jt == vec.end())
                        continue;
                    int sum1 = a + *jt;
                    int sum2 = total - sum1;
                    res = min(res, abs(sum1 - sum2));
                }
            }
        }
        return res;
    }
};