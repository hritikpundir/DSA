class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else if(s[i]==st.top()){
               st.pop();
            }
            else st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};