class Solution {
public:
    // Linear time, constant space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // insert into the end of nums1 which theoretically already has the 
        // correct amount of space allocated for it
        int left_idx = m - 1, right_idx = n - 1, insert_idx = nums1.size() - 1;
        
        while (left_idx >= 0 && right_idx >= 0)
        {
            if (nums1[left_idx] > nums2[right_idx])
            {
                nums1[insert_idx--] = nums1[left_idx--];
            }
            else
            {
                nums1[insert_idx--] = nums2[right_idx--];
            }
        }
        
        while (left_idx >= 0)
            nums1[insert_idx--] = nums1[left_idx--];
        
        while (right_idx >= 0)
            nums1[insert_idx--] = nums2[right_idx--];
    }
#if 0
    // Linear time, linear space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        std::vector<int> sorted(m + n);
        
        int left_idx = 0, right_idx = 0, insert_idx = 0;
        while (left_idx < m && right_idx < n)
        {
            if (nums1[left_idx] < nums2[right_idx])
                sorted[insert_idx++] = nums1[left_idx++];
            else
                sorted[insert_idx++] = nums2[right_idx++];
        }
        
        while (left_idx < m)
        {
            sorted[insert_idx++] = nums1[left_idx++];
        }
        
        while (right_idx < n)
        {
            sorted[insert_idx++] = nums2[right_idx++];
        }
        
        nums1 = sorted;
    }
#endif
};