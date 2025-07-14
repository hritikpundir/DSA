class Solution {
    //Hritik
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int delRow[], int delCol[]){
       vis[row][col]=1;
       int n = grid.size();
       int m = grid[0].size();
       for(int i=0; i<4; ++i){
        int nr = row+delRow[i];
        int nc = col+delCol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,delRow,delCol);
            }
       }
    }


public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delCol[] = {0,-1,0,1};
        int delRow[] = {-1,0,1,0};

        //traverse first and last row
        for(int j=0; j<m; ++j){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis,delRow,delCol);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis,delRow,delCol);
            }
        }

        //traverse 1st and last col
        for(int i=0; i<n; ++i){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis,delRow,delCol);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis,delRow,delCol);
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};