class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        int a = INT_MAX;
        int b = INT_MAX;
        for (int i = 0; i < n; i++) {
            if(nums[i] <= a){
                a = nums[i];
            }
            else if(nums[i] > a && nums[i] <= b){
                b = nums[i];
            }
            else{
                //triplet found
                return true;
            }
        }

        return false;
    }
};