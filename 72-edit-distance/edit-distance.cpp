class Solution {
public:
    int f(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        // base case
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);
        } else {
            int insertOp = f(i, j - 1, word1, word2, dp);
            int deleteOp = f(i - 1, j, word1, word2, dp);
            int replaceOp = f(i - 1, j - 1, word1, word2, dp);

            return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0)
            return m;
        if (m == 0)
            return n;

        // vector<vector<int>> dp(n+1,vector<int> (m+1, -1));
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        // return f(n-1,m-1, word1,word2, dp);

        // for(int i=0; i<=n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int insertOp = curr[j - 1];
                    int deleteOp = prev[j];
                    int replaceOp = prev[j - 1];

                    curr[j] = 1 + min(insertOp, min(deleteOp, replaceOp));
                }
            }
            prev = curr;
        }
        return curr[m];
    }
};