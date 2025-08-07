class Solution {
    //using space optimization
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int> (n,0));
        vector<int> front(n,0);
        for(int j=0; j<n; ++j){       //initializing last row values
            front[j] = triangle[n-1][j];     
        }

        for(int i=n-2; i>=0; --i){
            vector<int> curr(i+1,0);
            for(int j=i; j>=0; --j){
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                curr[j] = min(down,diag);
            }
            front = curr;
        }
        return front[0];
    }
};