class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.length();
        int start = 0;
        int maxlength = 1;
        
        auto expand = [&](int left, int right){
            while(left>=0 && right<n && s[left] == s[right]){
                int curLength = right - left + 1;
                if(curLength > maxlength){
                    maxlength = curLength;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for(int i=0; i<n; i++){
            expand(i,i);
            expand(i,i+1);
        }

        return s.substr(start, maxlength);
    }
};



// class Solution {
// public:
//     bool isPalindrom(string& s, int start, int end){
//         while(start<=end){
//             if(s[start] != s[end]) return false;
//             start++;
//             end--;
//         }
//         return true;
//     }

//     string f(string& s, int start, int end){
//         int n = s.length();
//         if(isPalindrom(s, start, end)){
//             return s.substr(start, end-start+1);
//         }
        
//         //3 cases
//         string left = f(s, start+1, end);
//         string right = f(s, start, end-1);
//         string both = f(s, start+1, end-1);

//         string longest = left;
//         if(right.length() > longest.length()){
//             longest = right;
//         }
//         if(both.length() > longest.length()){
//             longest = both;
//         }
//         return longest;
//     }

//     string longestPalindrome(string s) {
//         int n = s.length();
//         return f(s,0, n-1);
//     }
// };