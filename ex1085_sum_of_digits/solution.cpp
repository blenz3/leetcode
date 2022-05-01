class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int minimum(INT_MAX);
        for (auto num : nums) {
            minimum = std::min(num, minimum);   
        }
        
        return digitalSum(minimum) % 2 == 0 ? 1 : 0;
    }
    
    int digitalSum(int num) {
        int sum(0);
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        
        return sum;
    }
};
