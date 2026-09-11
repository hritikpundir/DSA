class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.length() != words.size())
            return false;

        // checking for bijection
        for (int i = 0; i < pattern.length(); i++) {
            if (charToWord.count(pattern[i]) &&
                charToWord[pattern[i]] != words[i]) {
                return false;
            }
            if (wordToChar.count(words[i]) &&
                wordToChar[words[i]] != pattern[i]) {
                return false;
            }
            charToWord[pattern[i]] = words[i];
            wordToChar[words[i]] = pattern[i];
        }

        return true;
    }
};