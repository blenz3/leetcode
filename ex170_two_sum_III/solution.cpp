class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        seen[number]++;   
    }
    
    bool find(int value) {
        for (auto num : seen) {
            int complement = value - num.first;
            if (complement == num.first && num.second < 2)
                continue;
            
            auto findIt = seen.find(complement);
            if (findIt == seen.end())
                continue;
            
            
            return true;
        }
        
        return false;
    }
    
private:
    unordered_map<int64_t, int16_t> seen;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
