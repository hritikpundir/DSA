class LRUCache {
    int capacity;
    //{key,val}
    list<pair<int,int>> cacheList;
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        auto nodeIt = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, nodeIt);

        return nodeIt->second;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            auto nodeIt = cacheMap[key];
            nodeIt->second = value;
            cacheList.splice(cacheList.begin(), cacheList, nodeIt);
            return;
        }

        if(cacheList.size() == capacity){ //full
            int lruKey = cacheList.back().first;
            // Remove it from both the map and the list
            cacheList.pop_back();
            cacheMap.erase(lruKey);
        }
        //insert new pair
        cacheList.push_front({key,value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */