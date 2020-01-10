class Solution {
public:
    int arrangeCoins(int n) {
        int64_t sum(0), i(0);
        while (sum <= n) {
            sum += i;
            i++;
        }
        return (sum == n) ? i - 1: i - 2; 
    }
};
