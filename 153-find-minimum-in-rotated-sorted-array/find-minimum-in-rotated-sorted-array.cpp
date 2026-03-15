class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        if (nums[low] < nums[high])  //not rotated
            return nums[low];

        while (low < high) {
            int mid = low + (high-low) / 2;
            if (nums[mid] > nums[mid + 1]) { 
                return nums[mid + 1];
            }
            if (nums[mid] >
                nums[low]) { // left part is sorted, ans in right pART
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return nums[0];  //runs for single element
    }
};