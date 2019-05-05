class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        //return removeDuplicatesSingleErase(nums);   
        //return removeDuplicatesRangeErase(nums);   
        return removeDuplicatesRealign(nums);   
    }
    
    int removeDuplicatesSingleErase(vector<int>& nums) {
        // We are going to do pairwise comparisons and do an
        // erase whenever we find a duplicate. Removing an element
        // is expensive for vectors so we should attempt to group the
        // erase operations to contiguous ranges where possible
        int i = 0;
        while (i < static_cast<int>(nums.size()) - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
                continue;
            }
            else
            {
                // not a dupe. Let's advance to the next number
                i++;
            }
        }        
        return nums.size();
    }
    
    int removeDuplicatesRangeErase(vector<int>& nums) {
        // We are going to do a range erase to limit the calls to erase. 
        int i = 0;
        while (i < static_cast<int>(nums.size()) - 1)
        {
            // If the pairwise comparison fails then we should just advance to the next element
            int j = i + 1;
            if (nums[i] != nums[j])
            {
                i++;
                continue;
            }
            
            // Find out how many dupes we have before erasing them all in one go
            while ( j < nums.size() && nums[i] == nums[j])
            {
                j++;
            }

            nums.erase(nums.begin() + i + 1, nums.begin() + j );
        }        
        
        return nums.size();
    }
    
    int removeDuplicatesRealign(vector<int>& nums) {
        // The general gameplan will be to move elements from the back of the list to the front in place
        // of duplicates as we find them. In this we avoid all calls to erase and just shift unique values
        int index = 0, unique_values = 0;
        while (index < nums.size())
        {
            if (nums[unique_values] != nums[index])
            {
                unique_values++;
                nums[unique_values] = nums[index];
            }
            
            index++;
        }
        
        return unique_values + 1;
    }
};