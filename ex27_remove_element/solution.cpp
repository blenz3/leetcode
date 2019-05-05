class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == val)
            {
                // We remove the current element. Don't increment index since a new value will be 
                // taking the place of nums[i]
                nums.erase(nums.begin() + i);
            }
            else
            {
                // This element was fine. Move on to the next
                i++;
            }
        }
        
        return nums.size();
    }
};