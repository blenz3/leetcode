class Solution {
public:
    int addDigits(int num) {
        while (num >= 10)
            num = reduce(num);
        
        return num;
    }
    
    int reduce(int num) {
        int sum(0);
        while (num != 0) {
            sum += (num % 10);
            num /= 10;
        }
        
        return sum;
    }
};
