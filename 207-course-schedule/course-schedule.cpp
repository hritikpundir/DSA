class Solution {
public:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1) return true;  // Found a cycle!
        if (visited[node] == 2) return false; // Already processed and safe
        
        visited[node] = 1; // Mark as currently visiting
        
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited)) {
                return true;
            }
        }
        
        visited[node] = 2; // Mark as fully processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        // Step 2: Track visited states (0 = unvisited, 1 = visiting, 2 = visited)
        vector<int> visited(numCourses, 0);
        
        // Step 3: Run DFS for each course
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (hasCycle(i, adj, visited)) {
                    return false; // Cycle detected, can't finish
                }
            }
        }
        
        return true;
    }
};