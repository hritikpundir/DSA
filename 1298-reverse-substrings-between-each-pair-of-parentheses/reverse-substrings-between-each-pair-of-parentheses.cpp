class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char c : s) {
            if (c != ')') {
                st.push(c);
            } else {
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); // pop '('
                for (char ch : temp) {
                    st.push(ch);
                }
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};