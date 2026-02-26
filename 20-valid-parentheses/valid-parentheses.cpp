class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            // opening bracket
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            // closing bracket
            else {
                if (st.empty())
                    return false;

                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                    st.pop();
                } else
                    return false;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};