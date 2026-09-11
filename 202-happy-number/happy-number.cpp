class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        int sum = 0;
        unordered_set<int> f;
        while(num){
            int a = num % 10;
            sum += (a*a);
            num = num / 10;
            if(num == 0){
                if(sum == 1) return true;
                if(f.find(sum) != f.end()) return false;
                f.insert(sum);
                num = sum;
                sum = 0;
            }
        }
        return true;
    }
};