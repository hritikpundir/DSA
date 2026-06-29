class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int low = 0;
        int high = k - 1;
        int cnt = 0;
        int res = 0;

        for (int i = low; i <= high; i++) {
            if (isVowel(s[i])) {
                cnt++;
            }
        }

        while (high < n) {
            res = max(res, cnt);
            low++;
            high++;
            if (high == n)
                break;
            if (isVowel(s[low - 1]))
                cnt--;
            if (isVowel(s[high]))
                cnt++;
        }
        return res;
    }
};