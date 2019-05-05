class Solution {
public:
    string intToRoman(int num) {
        // General gameplan is to greedily consume large values until we've gotten them all
       static const std::vector<std::pair<int32_t, std::string>> symbol_mapping {
           {1000, "M"},
           {900, "CM"},
           {500, "D"},
           {400, "CD"},
           {100, "C"},
           {90, "XC"},
           {50, "L"},
           {40, "XL"},
           {10, "X"},
           {9, "IX"},
           {5, "V"},
           {4, "IV"},
           {1, "I"},
       };
        
        std::string roman; // maybe should just operate on a buffer instead of having a bunch of allocations
        while (num != 0)
        {
            for (auto& symbol_pair : symbol_mapping)
            {
                if (num >= symbol_pair.first)
                {
                    num -= symbol_pair.first;
                    roman += symbol_pair.second;
                    
                    break;  // want to keep consuming the largest value
                }
            }
        }
        
        return roman;
    }
};