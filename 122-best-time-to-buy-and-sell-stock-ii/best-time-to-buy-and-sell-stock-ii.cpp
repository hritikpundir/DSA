// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int res = 0;
//         int buy = prices[0];
//         int sell = 0;

//         for(int i=1; i<n; i++){
//             if(prices[i] < buy){
//                 buy = prices[i];
//             }
//             else if(prices[i] > buy){
//                 sell = prices[i];
//             }
//             if(sell > buy){
//                 res = res + (sell-buy);
//                 buy = prices[i];
//                 sell = 0;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for (size_t i = 1; i < prices.size(); i++) {
            // If the price went up, grab the profit!
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        
        return max_profit;
    }
};