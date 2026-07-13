class Solution {
public:
    void backtrack(int start, vector<vector<int>>& res, vector<int>& diary, int k, int n, int sum){
        if(diary.size() == k){
            if(sum == n){
                res.push_back(diary);
            }
            return;
        }

        for(int i=start; i<=9; i++){
            if(sum + i > n) break;
            if((9 - i + 1) < (k - diary.size())) break; // Pruning!

            diary.push_back(i);
            backtrack(i+1, res, diary, k, n, sum+i);
            diary.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> diary;
        int sum = 0;
        int start = 1;

        backtrack(start, res, diary, k, n, sum);
        return res;
    }
};