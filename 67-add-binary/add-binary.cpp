class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        bool carry = 0; 
        int i = a.length() - 1;
        int j = b.length() - 1;

        while(i>=0 || j>=0 || carry){
            int digitA = (i>=0) ? a[i] - '0' : 0;
            int digitB = (j>=0) ? b[j] - '0' : 0;

            int total = digitA + digitB + carry;
            if(carry) carry = 0;
            if(total==2){
                total = 0;
                carry  = 1;
            }
            else if(total==3){
                total = 1;
                carry = 1;
            }

            sum += total + '0';
            if(i>=0)i--;
            if(j>=0)j--;
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};