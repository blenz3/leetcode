class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if (nums.empty())
            return {};
        
        vector<string> out;
        int startNumber = nums[0], prevNumber = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (prevNumber + 1 != nums[i]) {
                // printf("prev %d start %d i %d\n", prevNumber, startNumber, i);
                out.push_back(summaryInterval(startNumber, prevNumber));
                startNumber = prevNumber = nums[i];
            } else {
                prevNumber = nums[i];
            }
        }
        
        out.push_back(summaryInterval(startNumber, prevNumber));
        
        return out;
    }
    
    
    string summaryInterval(int start, int end) {
        char buffer[256];
        ::memset(buffer, 0, sizeof buffer);
        if (start == end) {
            ::snprintf(buffer, sizeof buffer, "%d", start);
        } else {
            ::snprintf(buffer, sizeof buffer, "%d->%d", start, end);    
        }
        
        return string(buffer);
    }
};
