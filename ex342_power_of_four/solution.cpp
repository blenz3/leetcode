class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || num == 2 || num == 3 || (num >= 5 && num < 16))
            return false;
        
        if (num == 4)
            return true;
            
        while (!(num & 0x3))
        {
            num = num >> 2;
        }
        
        return (num == 1);
    }
};