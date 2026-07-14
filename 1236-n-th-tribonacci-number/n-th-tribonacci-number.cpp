class Solution {
public:
    int fun(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = fun(n - 1, dp) + fun(n - 2, dp) + fun(n - 3, dp);
        return dp[n];
    }

    int tribonacci(int n) {
        // vector<int> dp(n + 1, -1);
        int prev2 = 0;
        int prev1 = 1;
        int prev = 1;

        for(int i=3; i<=n; i++){
            int curr = prev + prev1 + prev2;
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }
        if(n == 0) return 0;
        return prev;
    }
};