class Solution {
public:
    bool isUgly(int n) {
        if (n == 0)
            return false;
        
        vector<int> factors {5, 3, 2};
        for (auto factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        
        return (n == 1);
        
    }
};
