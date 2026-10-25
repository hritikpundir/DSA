class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;

        long long N = n;
        if (N < 0) {
            N = -N;
        }
        double extra = 1.0;
        while (N > 0) {
            if (N % 2 == 1)
                extra *= x;
            x = x * x;
            N = N / 2;
        }
        return n<0 ? 1.0/extra : extra;
    }
};