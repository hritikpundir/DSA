class Solution {
    //Hritik
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis,
    int delRow[], int delCol[]){
        int n = board.size();
        int m = board[0].size();
        vis[row][col]=1;
        for(int i=0; i<4; ++i){
            int nr = row+delRow[i];
            int nc = col+delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,board,vis,delRow,delCol);
            }
        }
    }

public:

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delCol[] = {0,-1,0,1};
        int delRow[] = {-1,0,1,0};

        //traverse first and last rows
        for(int j=0; j<m; ++j){
            if(!vis[0][j] && board[0][j]=='O'){
               dfs(0,j,board,vis,delRow,delCol);
            }

            if(!vis[n-1][j] && board[n-1][j]=='O'){
               dfs(n-1,j,board,vis,delRow,delCol);
            }
        }

        for(int i=0; i<n; ++i){
            if(!vis[i][0] && board[i][0]=='O'){
               dfs(i,0,board,vis,delRow,delCol);
            }

            if(!vis[i][m-1] && board[i][m-1]=='O'){
               dfs(i,m-1,board,vis,delRow,delCol);
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    //     return board;
     }
};