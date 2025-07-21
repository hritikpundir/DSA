class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        vector<vector<bool>> vis(n, vector(n, false));
        dist[0][0]=1;

        if(grid[0][0]==1 || grid[n-1][n-1]==1 ) return -1; //path is blocked
        if(n==1) return 1;

        q.push({1,{0,0}}); //{dist,{row,col}}
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            vis[r][c]=true;

            for(int i=0; i<8; ++i){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dis+1 < dist[nr][nc] && !vis[nr][nc]){
                    dist[nr][nc]=dis+1;
                    if(nr==n-1 && nc==n-1){
                        return dis+1;
                    }
                    q.push({dis+1,{nr,nc}});
                }
                
            }

        }
        return -1;
    }
};