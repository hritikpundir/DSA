// class Solution {
// public:
//     int reverseBits(int n) {
//         vector<int> res(32,0);
//         int ind = 0;
//         while(n > 0){
//             int rem = n % 2;
//             res[ind] = rem;
//             ind++;
//             n = n/2;
//         }
//          int ans = 0;
//          for(int i=0; i<32; i++){
//             ans += res[i] * pow(2,(31-i));
//          }
//          return ans;
//     }
// };


class Solution {
public:
    int reverseBits(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            // Shift ans to the left to make room, then add the last bit of n
            ans = (ans << 1) | (n & 1);
            // Shift n to the right to process the next bit
            n  = n>>1;
        }
        return ans;
    }
};