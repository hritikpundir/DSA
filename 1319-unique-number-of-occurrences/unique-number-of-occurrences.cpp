class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> f;

        for(int i=0; i<n; i++){
            f[arr[i]]++;
        }

        vector<int> freq;
        for(auto it: f){
            freq.push_back(it.second);
        }

        set<int> s(freq.begin(), freq.end());
        if(s.size() == freq.size()) return true;
        return false;

    }
};