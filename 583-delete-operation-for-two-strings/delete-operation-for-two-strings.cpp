class Solution {
    int lcs(string s, string t){
        int n = s.length();
        int m = t.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<int> prev(m+1,0),curr(m+1,0);

        //base case
        for(int j=0; j<=m; ++j) prev[j] = 0;

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1]==t[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return curr[m];
    }
public:
    int minDistance(string word1, string word2) {
        return word1.length() + word2.length() - (2*lcs(word1,word2));
    }
};