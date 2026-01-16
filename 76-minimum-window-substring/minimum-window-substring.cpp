class Solution {
public:
    bool sahi(vector<int> have, vector<int> needed){
        for(int i=0; i<256; i++){
            if(have[i]<needed[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m  = t.size();
        vector<int> have(256,0);
        vector<int> needed(256,0);

        if(n<m) return "";
        for(int i=0; i<m; ++i) needed[t[i]]++;

        int low=0;
        int res = INT_MAX;
        int start = -1;

        for(int high=0; high<n; ++high){
            have[s[high]]++;
            while(sahi(have,needed)){
                int len=high-low+1;    //length found
                if(res>len){           // result stored
                    res=len;
                    start=low;
                }
                //now shrink the window
                have[s[low]]--;
                low++;
            }
        }
        if(res==INT_MAX) return "";
        return s.substr(start,res);
    }
};