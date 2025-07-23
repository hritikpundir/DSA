class Solution {
    // Hritik
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        //  queue<pair<int,int>> q;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>  q;
        vector<int> travelTime(n + 1, 1e9);
        travelTime[k] = 0;
        travelTime[0] = 0;
        q.push({0, k}); //{time,node}

        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int time = it.first;
            int node = it.second;

            if (time < travelTime[node]) {
                travelTime[node] = time;
            }

            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int adjTime = iter.second;
                if(adjTime+time < travelTime[adjNode]){
                    travelTime[adjNode] = adjTime+time;
                    q.push({time + adjTime, adjNode});
                }

            }
        }
        int minTime = 0;
        for (int i = 0; i < n + 1; ++i) {
            minTime = max(minTime, travelTime[i]);
        }
        if (minTime == 1e9)
            return -1;
        return minTime;
    }
};