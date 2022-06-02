class Solution {
public:
    
    // Brute force
    //   - Check 1..n / 2 if it is a divisor
    //   - Sum up all the divisors 
    bool checkPerfectNumber(int num) {
        int divisorSum(0);
        for (int i = 1; i < (num / 2) + 1; ++i) {
            if (i != num && num % i == 0) {
                divisorSum += i;
            }
            
            if (divisorSum > num) {
                return false;
            }
        }
        
        return divisorSum == num;
    }
};
