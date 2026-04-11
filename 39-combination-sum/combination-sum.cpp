class Solution {
public:
    void findComb(int ind, vector<int>& candidates, int target, vector<int>& diary, vector<vector<int>>& ans){
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(diary);
            }
            return;
        }
        //not pick
        findComb(ind+1,candidates,target,diary,ans);

        //pick
        if(candidates[ind] <= target){
            diary.push_back(candidates[ind]);
            findComb(ind, candidates, target-candidates[ind], diary,ans);
            diary.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> diary;
        findComb(0,candidates,target,diary,ans);
        return ans;
    }
};