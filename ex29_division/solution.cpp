class Solution {
public:
    // Not allowed to use multiplication, division, or modulo so I guess we are going to 
    // count the times we can subtract divisor from dividend before divisor is > dividend
    int divide(int64_t dividend, int64_t divisor)
    {
        bool sign = (dividend < 0) != (divisor < 0); // only if one is negative then we set the sign
        dividend = (dividend < 0) ? dividend - dividend - dividend : dividend;
        divisor = (divisor < 0) ? divisor - divisor - divisor : divisor;
        
        if (dividend == 0)
            return 0;
        
        int64_t count = 0;
        if (divisor == 1)
        {
            count = dividend;
            dividend = 0;
        }
        
        // try to subtract by 4 times the amount first
        while (dividend >= divisor + divisor + divisor + divisor)
        {
            dividend -= (divisor + divisor + divisor + divisor);
            count += 4;
        }
        
        while (dividend >= divisor)
        {
            dividend -= divisor;
            count++;
        }
            
        if (sign)
            count = count - count - count;
        
        count = (count > INT_MAX) ? INT_MAX : count;
        count = (count < INT_MIN) ? INT_MIN : count;
        
        return count;
    }
};