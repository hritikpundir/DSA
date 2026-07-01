class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        int i = 0;
        while (i < n) {
            if (st.empty() || (st.top() < 0 && asteroids[i] < 0) ||
                asteroids[i] > 0) {
                st.push(asteroids[i]);
                i++;
            }

            else if (abs(st.top()) == abs(asteroids[i])) {
                st.pop();
                i++;
            } else {
                if (abs(asteroids[i]) > abs(st.top()))
                    st.pop();
                else
                    i++;
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};