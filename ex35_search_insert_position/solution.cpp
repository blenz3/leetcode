class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        // linear time search, constant space. Trawl through the list until we find a larger value. Return that index
        int i = 0;
        while (i < nums.size() && nums[i] < target)
        {
            i++;
        }
        
        return i;
    }
};