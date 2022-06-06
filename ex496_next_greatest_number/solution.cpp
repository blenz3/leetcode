class Solution {
public:

    // Brute force
    //   - For each number find a greater number in the opposite
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); ++i) {
            bool found(false);
            int nextGreatest = -1;
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                } else if (found && nums2[j] > nums1[i]) {
                    nextGreatest = nums2[j];
                    break;
                }
            }
            
            nums1[i] = nextGreatest;
        }
        
        return nums1;
    }

};
