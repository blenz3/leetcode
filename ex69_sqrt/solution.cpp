class Solution {
public:
    int mySqrt(double x) {
        double current = x, previous = 0;
        while (abs(current - previous) >= 1) {
            previous = current;
            current = 0.5 * (current + x / current);
        }
        
        return static_cast<int>(current);
    }
};
