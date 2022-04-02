class Solution {
public:
    
    // dumb thing jennifer made me do against my will!
    string toHex(int num) {
        if (num == 0) 
            return "0";
        
        uint32_t value = static_cast<uint32_t>(num);
        std::string out;
        while (value != 0) {
            int digit = value % 16;
            value /= 16;
            out.push_back(intToHexChar(digit));
        }
        
        return string(out.rbegin(), out.rend());

    }
    
    char intToHexChar(int val) {
        char izard[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        return izard[val];
    }
    
#if 0
    // Actual strategy - just use sprintf
    string toHex(int num) {
        char val[50];
        ::sprintf(val, "%x", num);
        return std::string(val);
    }
#endif
};
