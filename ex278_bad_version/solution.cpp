// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadVersion(int n) {
        //return bruteForceBadVersionSearch(n);
        return binaryBadVersionSearch(1, n);
    }
    
private:
    int bruteForceBadVersionSearch(int currentVersion) {
        bool badVersionFound = false;
        for (int i = currentVersion; i >= 0; --i) {
            if (!isBadVersion(i))
                return i + 1;
        }
        
        return -1;
    }
    
    int binaryBadVersionSearch(int64_t lower, int64_t upper) {
        if (lower == upper) {
            return lower;
        } else if (upper - lower == 1) {
            return (isBadVersion(lower)) ? lower : upper;
        }
        
        int64_t midpoint = (upper + lower) / 2;
        if (isBadVersion(midpoint)) {
            return binaryBadVersionSearch(lower, midpoint);
        } else {
            return binaryBadVersionSearch(midpoint, upper);
        }
    }
};
