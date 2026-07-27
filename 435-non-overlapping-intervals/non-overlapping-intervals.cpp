class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return (a[1] < b[1]); });

        // vector<vector<int>> ans;
        int end = intervals[0][1];
        // ans.push_back(intervals[0]);
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < end) {
                cnt++;
            } else
                end = intervals[i][1];
        }
        return cnt;
    }
};