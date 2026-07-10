class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0;
        int n = nums1.size();

        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.begin(), pairs.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        long long sum = 0;

        for (auto it : pairs) {
            pq.push(it.second);
            sum += it.second;

            if (pq.size() > k) {
                int small = pq.top();
                pq.pop();
                sum -= small;
            }

            if (pq.size() == k) {
                long long score = sum * it.first;
                res = max(res, score);
            }
        }
        return res;
    }
};