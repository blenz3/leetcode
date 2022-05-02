class Solution {
public:
    // Brute force
    //   - Copy to an empty secondary array such that one half are positive and one half are negative
    //   - Overwrite the input array alternating between large and small
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveHead = 0, negativeHead = nums.size() / 2;
        vector<int> out(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                out[positiveHead++] = nums[i];
            } else {
                out[negativeHead++] = nums[i];
            }
        }
        
        // With a balanced tree let's reset the pointers and overwite the existing
        positiveHead = 0, negativeHead = nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) { 
            if (i % 2 != 0) {
                nums[i] = out[positiveHead++];
            } else {
                nums[i] = out[negativeHead++];
            }
        }
        
        return nums;
    }
};
