class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        // no negative number is a power of 2
        if (n <= 0)
            return false;
        
        // special case 1 and 2 since they are just true and 2 causes problems for the right shift plan
        if ( n == 1 || n == 2)
            return true;
        
        // Keep shifting right by 1 until bit 0 is high. If it is a power of 2 then that will be the only high bit
        while ((n & 1) != 1)
        {
            n = n >> 1;
        }
        
        return (n == 1);
    }
};