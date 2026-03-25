class Solution {
public:
struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;         //min-heap
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> f;

        for(int i=0; i<n; i++){
            f[words[i]]++;
        }
        for(auto it: f){
            string word = it.first;
            int freq = it.second;

            pair<int,string> curr = {freq,word};
            pq.push(curr);

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};