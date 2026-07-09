class SmallestInfiniteSet {
    set<int> addedBack;
    int curr;

public:
    SmallestInfiniteSet() { curr = 1; }

    int popSmallest() {
        if (!addedBack.empty()) {
            int val = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return val;
        }
        return curr++;
    }

    void addBack(int num) {
        if (num < curr) {
            addedBack.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */