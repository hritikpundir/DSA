class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1 != n2) return false;

        unordered_map<char,int> f1;
        for(int i=0; i<n1; i++){
            f1[word1[i]]++;
        }

        unordered_map<char,int> f2;
        for(int i=0; i<n2; i++){
            f2[word2[i]]++;
        }

        set<char> s1(word1.begin(), word1.end());
        set<char> s2(word2.begin(), word2.end());
        if(s1 != s2) return false;

        vector<int> freq1;
        for(auto it: f1){
            freq1.push_back(it.second);
        }
        sort(freq1.begin(), freq1.end());

        vector<int> freq2;
        for(auto it: f2){
            freq2.push_back(it.second);
        }
        sort(freq2.begin(), freq2.end());
        if(freq1 != freq2) return false;

        return true;
    }
};