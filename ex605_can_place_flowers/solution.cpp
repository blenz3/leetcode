class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Basic pre-conditions. If no flowers to be added then it is always true
        // otherwise if the bed is empty or the number to be planted is more than 
        // are available plots then it is false
        if (n == 0) { 
            return true;
        } else if (flowerbed.empty() || n > flowerbed.size()) {
            return false;
        }
        
        return (availableSlots(flowerbed) >= n);
    }
    
    int availableSlots(vector<int>& flowerbed) {
        int count(0);
        for (int i = 0; i < flowerbed.size(); ++i) {
            if ((i - 1 < 0 || flowerbed[i - 1] == 0) &&
                (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0) && 
                flowerbed[i] == 0) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count;
    }
};
