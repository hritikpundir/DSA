class Solution {
    // int f(int ind,int target,vector<int>& coins){
    //     // base case
    //     if(ind == 0){
    //         if(target%coins[ind]==0) return target/coins[ind];
    //         else return 1e9;
    //     }

    //     int nottake = 0 + f(ind-1,target,coins);
    //     int take = 1e9;
    //     if(coins[ind]<=target) take = 1 + f(ind,target-coins[ind],coins);

    //     return min(take,nottake);
    // }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int> (amount+1,1e9));
        vector<int> prev(amount+1,1e9), curr(amount+1,1e9);

        // base case
        for(int t=0; t<=amount; ++t){
            if(t % coins[0] == 0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }

        for(int i=1;i<n;++i){
            for(int t=0;t<=amount;++t){
                int nottake = 0 + prev[t];
                int take = 1e9;
                if(coins[i]<=t) take = 1 + curr[t-coins[i]];

                curr[t] = min(take,nottake);
            }
            prev = curr;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];

    }
};