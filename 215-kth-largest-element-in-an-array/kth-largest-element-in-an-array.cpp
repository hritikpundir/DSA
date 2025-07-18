class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, target = nums.size() - k;
        while (left <= right) {
            int pivot = partition(nums, left, right);
            if (pivot == target) return nums[pivot];
            else if (pivot < target) left = pivot + 1;
            else right = pivot - 1;
        }
        return -1;
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right], i = left;
        for (int j = left; j < right; ++j) {
            if (nums[j] < pivot) swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[right]);
        return i;
    }
};