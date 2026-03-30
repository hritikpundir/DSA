class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        unordered_map<char,int> freq;
        unordered_map<char,int> free;
        for(int i=0; i<size; i++){
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }
        //max-heap
        priority_queue<pair<int,char>> pq;
        for(auto it: freq){
            pq.push({it.second,it.first});
        }
        int seat = 1;
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            while(!pq.empty()){    //for checking placable chars in heap
                pair<int,char> p = pq.top();
                pq.pop();
                int fr = p.first;
                char child = p.second;
                if(free[child] <= seat){
                    //place 
                    if(p.first > 1){
                        pq.push({p.first-1, child});
                    }
                    free[child] = seat + n + 1;
                    break;
                }
                else{
                    temp.push_back(p);
                } 
            }
            for(int i=0 ; i<temp.size(); i++){
                pq.push(temp[i]);
            }
            seat++;
        }
        return seat-1;
    }
};