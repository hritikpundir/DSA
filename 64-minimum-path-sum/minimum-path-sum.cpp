class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,0));
        vector<int> prev(m, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0)
                    curr[j] = grid[0][0];
                else {
                    int up = grid[i][j];
                    if (i > 0)
                        up = up + prev[j];
                    else
                        up = up + 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += curr[j - 1];
                    else
                        left = left + 1e9;

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};