class Solution {
    // int f(int i, int j,vector<vector<int>>& matrix){
    //     int n = matrix.size();
    //     if(j<0 || j>=n) return 1e9;     //base case
    //     if(i==0) return matrix[0][j];

    //     int up = matrix[i][j] + f(i-1,j,matrix);
    //     int upl = matrix[i][j] + f(i-1,j-1,matrix);
    //     int upr = matrix[i][j] + f(i-1,j+1,matrix);
    //     return min(up,min(upl,upr));
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> dp(n,vector<int> (n));
        vector<int> prev(n,0);     //for optimized solution
        //base case
        for(int j=0; j<n; ++j){     //initializing zeroth row
          prev[j] = matrix[0][j];
        }


        for(int i=1; i<n; ++i){
            vector<int> curr(n,0);
            for(int j=0; j<n; ++j){
                int up = matrix[i][j];
                int upl = matrix[i][j];
                int upr = matrix[i][j];

                up  = up + prev[j];
                if(j-1>=0)  upl  = upl + prev[j-1];
                else upl = 1e9;
                if(j+1<=n-1)  upr = upr + prev[j+1];
                else upr = 1e9;

                curr[j] = min(up,min(upl,upr));
            }
            prev = curr;
        }
        int minSum = 1e9;
        for(int j=0; j<n; ++j){
            minSum = min(minSum,prev[j]);
        }

        return minSum;
    }
};