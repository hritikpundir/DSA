class Solution {
public:
    int hammingWeight(int n) {
        int num = n;
        int cnt = 0;
        while(num){
            num /= 2;
            int bit = n & 1;
            if(bit == 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};