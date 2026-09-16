class Solution {
public:
    bool match(string haystack, string needle, int start, int end){
        int i = 0;
        int j = start;
        while(i<needle.length() && j<end){
            if(haystack[j] != needle[i]) return false;
            i++;
            j++;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int k = needle.length();
        if(n<k) return -1;
        int start =0;
        int end = -1;
        for(int i=0; i<k; i++){
            end++;
        }

        while(end < n){
            if(haystack.substr(start,k) == needle){
                return start;
            }
            else{
                start++;
                end++;
            }
        }
        return -1;
    }
};