struct DigitalSort
{
    inline bool operator() (int x, int y) {
        string sx(std::to_string(x)), sy(std::to_string(y));
        return (sx + sy) < (sy + sx);    
    }    
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), DigitalSort());
        if (*nums.rbegin() == 0)
            return "0";
        
        stringstream ss;
        for (auto rit = nums.rbegin(); rit != nums.rend(); ++rit) {    
            ss << *rit;
        }
        
        return ss.str();
    }
};
