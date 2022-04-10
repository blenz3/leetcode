static const int RED = 0;
static const int WHITE = 1;
static const int BLUE = 2;

class Solution {
public:
    
    // Strategy 
    //   - One pass is the goal
    //   - We could start from 0 and n - 1 and work our way in overwriting the previous values
    //   - we progress from left to right and back insert the blues and forward insert the reds
    //   - 
    void sortColors(vector<int>& nums) {
        int red = 0, index = 0, blue = nums.size() - 1;
        while (index <= blue) {
            if (nums[index] == RED) {
                swap(nums[index++], nums[red++]);
            } else if (nums[index] == BLUE) {
                swap(nums[index], nums[blue--]);
            } else {
                index++;
            }
        }
    }
    
    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }

#if 0
    // Strategy
    //  - No need to sort just get a count of each and then overwrite what is exists 
    void sortColors(vector<int>& nums) {
        int redCount(0), whiteCount(0), blueCount(0);
        for (auto& num : nums) {
            if (num == RED)
                redCount++;
            else if (num == WHITE)
                whiteCount++;
            else
                blueCount++;
        }
        
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i < redCount) {
                nums[i] = RED;
            } else if (i < redCount + whiteCount) {
                nums[i] = WHITE;
            } else {
                nums[i] = BLUE;
            }
        }
    }
#endif    

};
