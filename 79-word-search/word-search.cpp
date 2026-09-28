class Solution {
public:
    bool helper(int row, int col, vector<vector<char>>& board, string word,
                int idx, vector<vector<bool>>& vis, int delRow[],
                int delCol[]) {
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = true;
        if (idx == word.length())
            return true;

        for (int i = 0; i < 4; i++) {
            int nr = row + delRow[i];
            int nc = col + delCol[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] &&
                board[nr][nc] == word[idx]) {
                if (helper(nr, nc, board, word, idx + 1, vis, delRow, delCol)) {
                    return true;
                }

                // vis[row][col] = false;
            }
        }
        // backtrack
        vis[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(i, j, board, word, 1, vis, delRow, delCol)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};