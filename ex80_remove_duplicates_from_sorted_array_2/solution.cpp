class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIdx = 1, prevValue = nums[0], count(1), duplicatesRemoved(0);
        for (int i = insertIdx; i < nums.size(); ++i) {
            if (nums[i] == prevValue && count == 2) {
                duplicatesRemoved++;
            } else if (nums[i] == prevValue) {
                nums[insertIdx++] = nums[i];
                count++;
            } else if (nums[i] != prevValue) {
                nums[insertIdx++] = nums[i];
                count = 1;
                prevValue = nums[i];
            }
        }
        
        return nums.size() - duplicatesRemoved;
        //nums.erase(nums.begin() + nums.size() - duplicatesRemoved, nums.end());
        
        
    }
};
