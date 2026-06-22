class Solution {
public:
    int GCD(int a, int b) {
        // find gcd of a and b (where a > b)
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int gcd = 0;
        if (str1 + str2 != str2 + str1) {
            return "";
        } else {
            // GCD  of n,m
            if (n >= m)
                gcd = GCD(n, m);
            else
                gcd = GCD(m, n);

        }
        return str1.substr(0,gcd);
    }
};