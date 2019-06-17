
class Solution {
public:
    double myPow(double x, int n) {
        bool negative = n < 0 ? 1 : 0;
        
        int64_t exp = (n < 0) ? -1 * static_cast<int64_t>(n) : n;
        return (n < 0) ? 1 / myPowInternal(x, exp)  : myPowInternal(x, exp);
    }
    
    double myPowInternal(double x, int64_t n) 
    {
        if (n == 1) 
            return x;
        
        if (n == 0) 
            return 1;
        
        double result = myPowInternal(x, n / 2);
        
        // square the result
        result *= result;
        if (n % 2 != 0) 
            result *= x; // handle odd exponents
        
        return result;
    }
};
