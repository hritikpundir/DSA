class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char, int>> st;
        string res = "";

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (st.empty()) { // empty stack fill
                st.push({c, 1});
                continue;
            }
            if (st.top().first != c) { // not matching
                st.push({c, 1});
                continue;
            }
            // Case: c and st.top() are same
            if (st.top().second < (k - 1)) {
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second + 1}); // increasing count
                continue;
            }
            st.pop();
        }
        while (!st.empty()) {
            for (int i = 0; i < st.top().second; i++) {
                res += st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};