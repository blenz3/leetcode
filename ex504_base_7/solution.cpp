class Solution {
public:
    // Convert to base 7 
    //  - You basically mod 7 and have a carry 
    string convertToBase7(int num) {
        
        if (num >= 0 && num < 7) {
            return string(1, '0' + num);
        } else if (num > -7 && num < 0) {
            return "-" + string(1, '0' + (-1 * num));
        }
        
        int sign = (num < 0) ? -1 : 1;
        num *= sign;
        
        std::string out;
        while (num != 0) {
            int remainder = num % 7;
            out.push_back('0' + remainder);
            num /= 7;
        }
        
        if (sign == -1)
            out.push_back('-');
        
        std::reverse(out.begin(), out.end());
        return out;
    }
};
