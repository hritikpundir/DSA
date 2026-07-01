class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char> st;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        s = "";

        while (!st.empty()) {
            char c = st.top();
            st.pop();
            s += c;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};