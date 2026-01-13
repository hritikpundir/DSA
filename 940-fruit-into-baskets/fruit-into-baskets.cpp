class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int ans = -1;
        unordered_map<int,int> ftype;

        while(high < fruits.size()){
            ftype[fruits[high]]++;
            while(ftype.size() > 2){
                ftype[fruits[low]]--;
                if(ftype[fruits[low]] == 0) ftype.erase(fruits[low]);
                low++;
            }
            int len = high - low +1;
            ans = max(ans,len);
            high++;
        }
        return ans;
    }
};