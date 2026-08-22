class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> f;
        f['I'] = 1;
        f['V'] = 5;
        f['X'] = 10;
        f['L'] = 50;
        f['C'] = 100;
        f['D'] = 500;
        f['M'] = 1000;

        int num = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1 && f[s[i]] < f[s[i + 1]]) {
                num -= f[s[i]];
            } else
                num += f[s[i]];
        }
        return num;
    }
};