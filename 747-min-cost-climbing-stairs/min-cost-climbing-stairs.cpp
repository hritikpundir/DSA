class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1,-1);
        int next2 = 0;
        int next = cost[n-1];
        for(int i=n-2; i>=0; i--){
            int curr = cost[i] + min(next, next2);
            next2 = next;
            next = curr;
        }
        return min(next,next2);
    }
};