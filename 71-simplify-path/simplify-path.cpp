class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        vector<string> st;

        vector<string> tokens;
        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {
            tokens.push_back(token);
        }

        for (const string& token : tokens) {
            if (token.empty() || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(token);
            }
        }
        for (const string& dir : st) {
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }
};