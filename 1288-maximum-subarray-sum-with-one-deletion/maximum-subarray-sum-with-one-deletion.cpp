class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int result = arr[0];
        for (int i = 1; i < n; ++i) {
            int prevNoDelete = nodelete;
            int prevOneDelete = onedelete;
            int v;
            if (prevOneDelete == INT_MIN) {
                v = arr[i];
            } else {
                v = prevOneDelete + arr[i];
            }

            onedelete = max(v, prevNoDelete);
            nodelete = max(prevNoDelete + arr[i], arr[i]);
            result = max(result, max(onedelete, nodelete));
        }
        return result;
    }
};