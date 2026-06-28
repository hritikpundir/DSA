class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == (k - nums[i]) &&  freq[nums[i]] < 2){
                continue;
            }
            if(freq[nums[i]] > 0 && freq[k - nums[i]] > 0){
                freq[nums[i]]--;
                freq[k-nums[i]]--;
                cnt++;
            }
        }

        return cnt;

    }
};