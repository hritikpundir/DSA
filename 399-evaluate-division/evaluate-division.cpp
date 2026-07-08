class Solution {
public:
    bool dfs(string node, string dest, unordered_map<string, unordered_map<string, double>>& adj, unordered_set<string>& vis, double& ans, double temp){
        if(vis.find(node) != vis.end()) return false;
        vis.insert(node);
        if(node == dest){
            ans = temp;
            return true;
        }
        for(auto it: adj[node]){
            if(dfs(it.first, dest, adj, vis, ans, temp * it.second))
                return true;
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u][v] = val;
            adj[v][u] = 1.0 / val;
        }
        vector<double> finalAns;
        for(auto it: queries){
            string divident = it[0];
            string divisor = it[1];
            if(adj.find(divident) == adj.end() || adj.find(divisor) == adj.end()){
                finalAns.push_back(-1.0);
            }
            else{
                unordered_set<string> vis;
                double ans = -1.0;
                double temp = 1.0;
                dfs(divident, divisor, adj, vis, ans, temp);
                finalAns.push_back(ans);
            }
        }
        return finalAns;
    }
};