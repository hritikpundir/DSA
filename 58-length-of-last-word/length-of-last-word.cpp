class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;

        // Step 1: Skip trailing spaces at the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};