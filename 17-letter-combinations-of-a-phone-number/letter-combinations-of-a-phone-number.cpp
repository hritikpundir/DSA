class Solution {
public:
    void fun(string& digits, int n, int idx, string& diary, vector<string>& res,
             unordered_map<char, string>& f) {
        if (idx == n) {
            res.push_back(diary);
            return;
        }
        string choices = f[digits[idx]]; // eg. 2 or 3
        for (int i = 0; i < choices.size(); i++) {
            diary.push_back(choices[i]);
            fun(digits, n, idx + 1, diary, res, f);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        string diary = "";
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";
        fun(digits, n, 0, diary, res, f);
        return res;
    }
};