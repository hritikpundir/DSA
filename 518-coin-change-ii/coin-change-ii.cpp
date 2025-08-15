class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int> (amount+1,0));
        vector<int> prev(amount+1,0), curr(amount+1,0);

        //base case
        for(int t=0; t<=amount; ++t){
            if(t % coins[0] == 0) prev[t] = 1;
            else prev[t] =  0;
        }

        for(int i=1; i<n; ++i){
            for(int t=0; t<=amount; ++t){
                long long nottake = prev[t];
                long long take = 0;
                if(coins[i]<=t) take = curr[t-coins[i]];

                curr[t] = take + nottake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};