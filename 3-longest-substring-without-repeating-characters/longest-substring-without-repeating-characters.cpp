class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = 0;
        int ans = 0;
        unordered_map<char,int> f;

        while(high < s.length()){
            f[s[high]]++;
            int k = high-low+1;
            while(f.size() < k){     //duplicate chars in substring
              f[s[low]]--;
              if(f[s[low]] == 0) f.erase(s[low]);
              low++;
              k = high - low + 1;     //k also changes when low changes
            }

            int len = high-low+1;
            ans = max(len,ans);
            high++;
        }
        return ans;
    }
};