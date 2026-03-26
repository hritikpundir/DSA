class Solution {
public:
struct cmp {
       bool operator()(pair<int,char>& a, pair<int,char>& b) {
           if(a.first == b.first)
               return a.second < b.second;   
           return a.first < b.first;       //max-heap
       }
   };

    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int> f;
        for(int i=0; i<n; i++){
            f[s[i]]++;
        }

        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;
        for(auto it: f){
            char letter = it.first ;
            int freq = it.second ;
            pair<int,char> curr = {freq,letter};
            pq.push(curr);
        }
        string res = "";
        int seat = 0;

        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            if(seat==0 || res[seat-1] != p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0) pq.push(p);
            }

            else{
                //place next highest freq character
                if(pq.empty()) return "";
                pair<int,char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first > 0) pq.push(p2);

                pq.push(p); //popped earlier
            }
        }
        return res;
    }
};