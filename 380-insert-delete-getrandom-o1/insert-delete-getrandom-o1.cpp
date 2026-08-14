class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> indices;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(indices.find(val) != indices.end()){
            return false;
        }

        nums.push_back(val);
        int ind = nums.size() - 1;
        indices[val] = ind;
        return true;
    }
    
    bool remove(int val) {
        if(indices.find(val) == indices.end()){
            return false;
        }
        int ind_to_remove = indices[val];
        int last_val = nums.back();

        //swap
        nums[ind_to_remove]  = last_val;
        indices[last_val] = ind_to_remove;

        //pop
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */