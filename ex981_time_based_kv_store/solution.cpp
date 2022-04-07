
class TimeMap {
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        auto find = timeMap.find(key);
        if (find == timeMap.end()) {
            return "";
        }
        
        auto& entries = find->second;
        if (timestamp < entries[0].second)
            return "";
        else if (timestamp >= entries.back().second) 
            return entries.back().first;
        
        int start = 0, end = entries.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (timestamp == entries[mid].second) {
                return entries[mid].first;
            } else if (timestamp < entries[mid].second) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        if (timestamp < entries[start].second)
            start--;
   
        return entries[start].first;
    }
    
private:
    std::unordered_map<string, vector<pair<string, int>>> timeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
