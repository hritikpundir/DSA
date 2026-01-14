class Solution {
public:
    int find(vector<int>& a) {
        int maxc = -1;
        for (int i = 0; i < 26; i++)
            maxc = max(maxc, a[i]);
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int low = 0;
        int high = 0;
        vector<int> f(26, 0);
        int ans = INT_MIN;

        for (high = 0; high < s.length(); high++) {
            f[s[high] - 'A']++;
            int maxcnt = find(f);
            int len = high - low + 1;
            int diff = len - maxcnt;

            while (diff > k) {
                f[s[low] - 'A']--; // maxcnt can change
                low++;             // len will change
                maxcnt = find(f);
                len = high - low + 1;
                diff = len - maxcnt;
            }
            len = high - low + 1;
            ans = max(ans, len);
        }
        return ans;
    }
};