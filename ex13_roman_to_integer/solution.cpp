class Solution {
public:
    int romanToInt(string s) {
       static const std::unordered_map<std::string, int32_t> symbol_mapping {
           {"I", 1},
           {"IV", 4},
           {"V", 5},
           {"IX", 9},
           {"X", 10},
           {"XL", 40},
           {"L", 50},
           {"XC", 90},
           {"C", 100},
           {"CD", 400},
           {"D", 500},
           {"CM", 900},
           {"M", 1000},
       };

        int integer_sum(0);
        
        size_t i = 0; 
        while (i < s.length())
        {
            std::unordered_map<std::string, int32_t>::const_iterator it = symbol_mapping.end();
            
            // Try to set the current symbol to a 2 character symbol if it is encoded.
            // This gets us the special cases for 'IV', 'CM', etc.
            if (i + 1 < s.length())
            {
                it = symbol_mapping.find(s.substr(i, 2));
            }
            
            // Our two character lookup failed. Let's fallback to one character
            if (it == symbol_mapping.end())
            {
                it = symbol_mapping.find(s.substr(i, 1)); // guranteed per spec to succeed
            }
            
            integer_sum += it->second; // accumulate the value
            i += it->first.length(); // move the pointer along by either one or two characters
            
        }
        return integer_sum;
    }
};