class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        long long maxiArea = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            long long area = width * minHeight;
            maxiArea = max(maxiArea, area);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxiArea;
    }
};