class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        
        int64_t product = 1;
        while (product < n) {
            product *= 3;
        }

        return (n == product);
        
        
        
    }
};
