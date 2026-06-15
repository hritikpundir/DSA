class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int time = 0;

        int x[] = {-1,0,1,0};
        int y[] = {0,-1,0,1};
        queue<pair<int,int>> q;

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = -2; // -2 for visited indication
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0){
            time++;
            int nRow;
            int nCol;
            int s = q.size();
            while(s--){
                pair<int,int> p = q.front();
                q.pop();
                int row = p.first;
                int col = p.second;

                for(int k=0; k<4; ++k){
                    nRow = row + x[k];
                    nCol = col + y[k];

                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == 1 ){
                        q.push({nRow,nCol});
                        grid[nRow][nCol] = -2;
                        fresh--;
                    }
                }
            }
        }

        if(fresh > 0) return -1;
        return time;
    }
};