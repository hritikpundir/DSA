class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n,0);
        vector<int> safeNodes;
        
        
        for(int i=0; i<n; ++i){
             for(auto it: graph[i]){
               reverseGraph[it].push_back(i);
               indegree[i]++;
          }
        }
        for(int i=0; i<n; ++i){
         if(indegree[i]==0) q.push(i);
         }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:reverseGraph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            }
        
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};