class Solution {
public:
    struct cmp {
        bool operator()(pair<int, vector<int>>& a, pair<int, vector<int>>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first; // max-heap
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                       cmp>
            pq;

        for (auto& point : points) {
            int dist = (point[0])*(point[0]) + (point[1])*(point[1]);
            pair<int, vector<int>> curr = {dist, point};

            pq.push(curr);
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};