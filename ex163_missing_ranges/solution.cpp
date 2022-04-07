class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        if (nums.empty()) {
            return vector<string>{missingInterval(lower, upper)};
        }
        
        vector<string> out;
        int missingStart = -1, prevNumber = INT_MIN;
        for (auto& num : nums) {
            if (prevNumber == INT_MIN && lower < num) {
                out.push_back(missingInterval(lower, num - 1));
                lower = num + 1;
            }
            else if (lower < num) {
                out.push_back(missingInterval(prevNumber + 1, num - 1));
                lower = num + 1;
            } else {
                lower = num + 1;
            }
            prevNumber = num;
        } 
        
        if (upper > nums.back()) {
            out.push_back(missingInterval(nums.back() + 1, upper));
        }
        
        return out;
        
    }
    
    string missingInterval(int start, int end) {
        if (start == end) {
            return std::to_string(start);
        } else {
            return std::to_string(start) + "->" + std::to_string(end);
        }
    }
    
};
