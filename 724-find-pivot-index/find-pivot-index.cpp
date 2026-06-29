class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n) ;
        leftSum[0] = 0;
        int lSum = nums[0];
        for(int i=1; i<n; i++){
            leftSum[i] = lSum;
            lSum += nums[i];
        }

        vector<int> rightSum(n) ;
        rightSum[n-1] = 0;
        int rSum = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightSum[i] = rSum;
            rSum += nums[i];
        }

        for(int i=0; i<n; i++){
            if(leftSum[i] == rightSum[i]){
                return i;
            }
        }
        return -1;
    }
};