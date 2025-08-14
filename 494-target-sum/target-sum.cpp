class Solution {
    int findWays(vector<int>& nums,int target){
        int n = nums.size();
        vector<int> prev(target+1,0), curr(target+1,0);
        if(nums[0]==0) prev[0] = 2;
        else prev[0] = 1;

        if(nums[0]!=0 && nums[0]<=target ) prev[nums[0]] = 1;

        for(int ind=1; ind<n; ++ind){
            for(int t=0; t<=target; ++t){
                int nottake = prev[t];
                int take = 0;
                if(nums[ind]<=t) take = prev[t-nums[ind]];

                curr[t] = (nottake+take);
            }
            prev = curr;
        }
        return prev[target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); ++i){
            totalSum+=nums[i];
        }
        if(totalSum<target || (totalSum-target) % 2) return 0;
        return findWays(nums,(totalSum-target)/2);
    }
};