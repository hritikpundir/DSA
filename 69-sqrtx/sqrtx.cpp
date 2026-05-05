class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        if(x <= 1) return x;
        int low = 1;
        int high = x;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(mid*mid <= x){
                ans = max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};