class Solution {
public:
    void reverseRange(string& s, int l, int r) {
        while (l < r)
            swap(s[l++], s[r--]);
    }

    void reverseEachWord(string& s) {
        int n = s.length();
        int start = 0, end = 0;

        while (start < n) {
            while (end < n && s[end] != ' ')
                end++;
            reverseRange(s, start, end - 1);
            start = end + 1;
            end = start;
        }
    }
    string reverseWords(string s) {

        int n = s.length();
        int i = 0, j = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        bool spacePending = false;

        // Step 2: Copy characters and skip extra spaces
        while (i < n) {
            if (s[i] != ' ') {
                if (spacePending) {
                    s[j++] = ' '; // Insert one space between words
                    spacePending = false;
                }
                s[j++] = s[i++]; // Copy non-space character
            } else {
                spacePending = true; // Mark that a space has been seen
                i++;                 // Skip the space
            }
        }

        // Step 3: Remove trailing space if any
        if (j > 0 && s[j - 1] == ' ')
            j--;

        // Step 4: Resize string to the new length
        s.resize(j);
        reverseRange(s, 0, s.length() - 1);
        reverseEachWord(s);
        return s;
    }
};