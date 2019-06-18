class Solution {
public:
    
    int getNext(vector<int>& nums1, size_t& nums1_idx, vector<int>& nums2, size_t& nums2_idx)
    {
        int out(INT_MAX);
        if (nums1_idx < nums1.size() && nums2_idx < nums2.size() && nums1[nums1_idx] < nums2[nums2_idx])
        {
            out = nums1[nums1_idx++];
        }
        else if (nums1_idx < nums1.size() && nums2_idx < nums2.size() && nums1[nums1_idx] >= nums2[nums2_idx]) 
        {
            out = nums2[nums2_idx++];
        }
        else if (nums1_idx < nums1.size())
        {
            out = nums1[nums1_idx++];
        }
        else
        {
            out = nums2[nums2_idx++];
        }
        return out;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        bool is_even = ((nums1.size() + nums2.size()) % 2 == 0);
        
        // We want to move to the middle, but for an even number we want the middle - 1 since we are grabbing 2
        size_t num_to_move(((nums1.size() + nums2.size()) / 2));
        if (is_even)
        {
            num_to_move--;
        }
        
        // Scoot our indexes over to the number preceding the middle
        size_t nums1_idx(0), nums2_idx(0);
        while (num_to_move != 0)
        {
            // Move one space over
           getNext(nums1, nums1_idx, nums2, nums2_idx);
            --num_to_move;
        }
        
        // Grab the median and if it  is an even length combined array grab the next as well and take the average
        double median = getNext(nums1, nums1_idx, nums2, nums2_idx);
        if (is_even)
        {
            median += getNext(nums1, nums1_idx, nums2, nums2_idx);
            median /= 2;
        }
        
        return median;
    }
};