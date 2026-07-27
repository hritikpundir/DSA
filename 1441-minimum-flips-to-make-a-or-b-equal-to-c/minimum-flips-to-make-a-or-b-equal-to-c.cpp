class Solution {
public:
    int minFlips(int a, int b, int c) {
        int mis = (a | b) ^ c;
        int double_flips = (a & b & ~c);

        int cnt = 0;
        while (mis > 0) {
            if (mis & 1) {
                cnt++;
            }
            mis = mis >> 1;
        }
        
        while (double_flips > 0) {
            if (double_flips & 1) {
                cnt++;
            }
            double_flips = double_flips >> 1;
        }

        return cnt;
    }
};