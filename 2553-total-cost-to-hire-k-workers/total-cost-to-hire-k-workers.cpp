class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        int i = 0;
        for (i = 0; i < candidates; i++) {
            pq.push({costs[i], i});
        }

        int j = n - 1;
        for (j = n - 1; j > (n-1-candidates); j--) {
            if(j < i) break;
            pq.push({costs[j], j});
        }

        while (k--) {
            pair<int, int> p = pq.top();
            int val = p.first;
            int ind = p.second;

            pq.pop();
            cost += val;
            if (ind < i && i <= j) { // first candidates workers
                pq.push({costs[i], i});
                i++;
            } 
            else if (ind > j && i <= j) { // second candidates workers
                pq.push({costs[j], j});
                j--;
            }
        }
        return cost;
    }
};