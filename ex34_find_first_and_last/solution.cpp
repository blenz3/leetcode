class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearchRange(nums, target);
        //return bruteForceSearchRange(nums, target);
    }
    
private:
    
    // Get the index for the element or it's closest value
    int binarySearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int midpoint = (left + right) / 2;
            if (nums[midpoint] < target) {
                left = midpoint + 1;
            } else if (nums[midpoint] > target) {
                right = midpoint - 1;
            } else {
                return midpoint;
            }
        }
        
        return left;
    }

    vector<int> binarySearchRange(const vector<int>& nums, int target) {
        if (nums.empty()) 
            return std::vector<int>{-1, -1};
        
        // Search for the target itself
        int target_idx = binarySearch(nums, target);
        if (nums[target_idx] != target) {
            return std::vector<int>{-1, -1};
        }
        
        // Search for a smaller number
        int smaller_idx = binarySearch(nums, target - 1);
        while (nums[smaller_idx] != target) {
            smaller_idx++;
        }
        
        // Search for a larger number
        int larger_idx = binarySearch(nums, target + 1);
        while (nums[larger_idx] != target) {
            larger_idx--;
        }
        
        return std::vector<int>{smaller_idx, larger_idx};
    }
    
    vector<int> bruteForceSearchRange(const vector<int>& nums, int target) {
        std::vector<int> range { INT_MAX , INT_MIN };
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                range[0] = std::min(range[0], i);
                range[1] = std::max(range[1], i);
            }
        }
        return (range[0] == INT_MAX) ? std::vector<int>{ -1, -1 } : range;
    }
};
