class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int len = min(n,m);

        int i = 0;
        for(i=0; i<len; i++){
            ans += word1[i];
            ans += word2[i];
        }
        if(n<m){
            while(i < m){
                ans += word2[i];
                i++;
            }
        }
        if(m<n){
            while(i < n){
                ans += word1[i];
                i++;
            }
        }
        return ans;
    }
};