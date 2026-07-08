class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int& changes){
        vis[node] = true;

        for(auto& it: adj[node]){
            int neigh = it.first;
            int direc = it.second;

            if(!vis[neigh]){
                if(direc == 1) changes++;

                dfs(neigh, adj, vis, changes);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        int changes = 0;

        for(auto it: connections){
            int src = it[0];
            int dest = it[1];
            adj[src].push_back({dest, 1});  //orginal directions
            adj[dest].push_back({src, 0}); //reversed direction
        }
        
        vector<bool> vis(n,false);

        dfs(0, adj, vis, changes);

        return changes;
    }
};