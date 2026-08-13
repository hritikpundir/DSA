class Solution {
public:
    bool isAlpha(char c){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        while(left < right){
            while(left < right && !isAlpha(s[left])){
                left++;
            }
            while(left < right && !isAlpha(s[right])){
                right--;
            }

            char c1 = tolower(s[left]);
            char c2 = tolower(s[right]);
            if(c1 != c2) return false;
            left++;
            right--;
        }
        return true;
    }
};