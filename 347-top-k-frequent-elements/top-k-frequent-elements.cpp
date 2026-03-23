class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> f;
        for (int i = 0; i < n; ++i) {
            f[nums[i]]++;
        }

        for (auto it : f) {
            int element = it.first;
            int freq = it.second;

            pair<int, int> curr = {freq, element};
            pq.push(curr);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};