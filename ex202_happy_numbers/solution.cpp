class Solution {
public:
    
    bool isHappy(int n) {
        int runner = replace(replace(n));
        while (runner != 1 && n != runner) {
            n = replace(n);
            runner = replace(replace(runner));
        }
        
        return (runner == 1);
    }
    
#if 0
    // Cache results to find a cycle
    bool isHappy(int n) {
        // Maintain a count of values to assert that we don't end up in the same spot twice
        unordered_map<int, int> counts;
        
        while (n != 1 && counts[n] < 1) {
            counts[n]++;
            n = replace(n);
        }
        
        return (n == 1);
    }
#endif
    
private:
    int replace(int n) {
        int sum(0);
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += (digit * digit);
        }
        return sum;
    }
};
