class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);
        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++){
            int cnt = m;
            int low = 0;
            int high = m-1;

            while(low <= high){
                //to find lower bound
                int guess = low + (high-low)/2;
                long long strength = (long long)spells[i] * potions[guess];
                if(strength < success){
                    low = guess + 1;
                }
                else{
                    high = guess - 1;
                }
            }
            pairs[i] = m - low;
        }
        return pairs;
    }
};