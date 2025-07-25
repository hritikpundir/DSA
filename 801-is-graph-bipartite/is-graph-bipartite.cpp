class Solution {
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& graph){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it]==-1){
                col = (color[node]==0) ? 1 : 0;
                if (dfs(it,col,color,graph)==false) return false;
            }
            else if(color[it]==color[node]) return false;

        }
        return true;
    } 
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n;++i){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false)  return false;
            } 
        }
        return true;
    }
};