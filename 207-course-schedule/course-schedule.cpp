class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            indegree[prerequisites[i][1]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (cnt == numCourses)
            return true;
        return false;
    }
};