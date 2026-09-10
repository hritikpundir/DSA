class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<char, int> f;
        for (int i = 0; i < num.length(); i++) {
            f[num[i]]++;
        }

        string left_half = "";
        string middle = "";

        for (char digit = '9'; digit >= '0'; digit--) {
            if (f[digit] % 2 == 1 && middle.empty()) {
                middle = digit;
            }

            int pairs = f[digit] / 2;

            if (digit == '0' && left_half.empty()) {
                continue;
            }
            while (pairs--) {
                left_half += digit;
            }
        }

        string right_half = "";
        for (int i = left_half.length() - 1; i >= 0; i--) {
            right_half += left_half[i];
        }
        string ans = left_half + middle + right_half;
        if(ans.empty()) return "0";
        return ans;
    }
};