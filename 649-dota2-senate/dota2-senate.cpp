class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant;
        queue<int> dire;
        
        for(int i=0; i<n; i++){
            if(senate[i] == 'R'){
                radiant.push(i);
            }
            else{
                dire.push(i);
            }
        }

        // if(radiant.size() > dire.size()) return "Radient";
        // else if(radiant.size() < dire.size()) return "Dire";

        
        while(!radiant.empty() && !dire.empty()){
            int r_idx = radiant.front();
            int d_idx = dire.front();

            if(r_idx < d_idx){
                dire.pop();
                radiant.pop();
                radiant.push(r_idx + n);
            }
            else{
                radiant.pop();
                dire.pop();
                dire.push(d_idx + n);
            }
        }
        if(!radiant.empty()) return "Radiant";
        return "Dire";
    }
};