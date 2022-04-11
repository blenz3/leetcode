class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        vector<int> lis(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; --i) {
            int maxPaths = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    maxPaths = std::max(maxPaths, lis[j] + 1);
                }
            }    
            
            lis[i] = maxPaths;
        }
        
        int maxIs = 0;
        for (auto & n : lis) {
            maxIs = std::max(maxIs, n);
        }
        return maxIs;
    }
    
    void printVector(const vector<int>& v) {
        printf("[");
        for (auto n : v) {
            printf("%d, ", n);
        }
        printf("]\n");
    }
};
