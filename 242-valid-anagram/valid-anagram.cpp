class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) return false;
        unordered_map<char,int> mpp;
        for(int i=0; i<s.length(); ++i){
            if(mpp.find(s[i]) == mpp.end()) mpp.insert({s[i],1});
            else mpp[s[i]]++;
        }

        for(int i=0; i<t.length(); ++i){
            if(mpp.find(t[i]) == mpp.end()) return false;
            else mpp[t[i]]--;
        }

        for(auto it: mpp){
            if(it.second != 0) return false;
        }
        return true;
    }
};