static const int NOT_FOUND = -1;

class LRUCache {
public:
    LRUCache(int capacity_) 
        : capacity(capacity_) 
        , hashTable()
        , recentlyUsed()
    {
        
    }
    
    int get(int key) {
        auto findIt = hashTable.find(key);
        if (findIt == hashTable.end()) {
            return NOT_FOUND;
        }

        recentlyUsed.erase(findIt->second.second);
        recentlyUsed.push_back(key);
        findIt->second.second = --recentlyUsed.end();
        
        return findIt->second.first;
    }
    
    void put(int key, int value) {
        auto findIt = hashTable.find(key);
        if (findIt != hashTable.end()) {
            recentlyUsed.erase(findIt->second.second);
        }
        
        recentlyUsed.push_back(key);
        hashTable[key] = make_pair(value, --recentlyUsed.end());
        
        // Remove an old element
        if (recentlyUsed.size() > capacity) {
            hashTable.erase(recentlyUsed.front());
            recentlyUsed.pop_front();        
        }
    }
    
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> hashTable;
    std::list<int /*key*/> recentlyUsed; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
