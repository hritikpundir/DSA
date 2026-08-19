class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int bit=0; bit<32; bit++){
            int bit_sum = 0;
            for(int i=0; i<nums.size(); i++){
                if(((nums[i] >> bit) & 1) == 1) bit_sum++;
            } 

            // bit-sum calculated for pod i
            if(bit_sum % 3 != 0){
                res = res | (1 << bit);
            }
        }
        return res;
    }
};