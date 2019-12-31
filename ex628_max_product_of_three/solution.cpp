class Solution {
public:
    
    int maximumProduct(vector<int>& nums) {
        std::priority_queue<int, std::vector<int>, greater<int>> maxq(nums.begin(), nums.begin() + 3);
        std::priority_queue<int, std::vector<int>, less<int>> minq(nums.begin(), nums.begin() + 3);
        for (int i = 3; i < nums.size(); ++i) {
            if (maxq.top() < nums[i]) {
                maxq.pop();
                maxq.push(nums[i]);
            }
            
            if (minq.top() > nums[i]) {
                minq.pop();
                minq.push(nums[i]);
            }
        }
        
        int max1, max2, max3;
        max3 = maxq.top();
        maxq.pop();
        max2 = maxq.top();
        maxq.pop();
        max1 = maxq.top();
        
        int min1, min2;
        minq.pop();
        min2 = minq.top();
        minq.pop();
        min1 = minq.top();
        
        return std::max(max1 * max2 * max3, max1 * min1 * min2);
    }
    
#if 0
    // Brute force just iterate everything
    int maximumProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    maxProduct = std::max(maxProduct, nums[i] * nums[j] * nums[k]);
                }
            }
        }
        
        return maxProduct;
    }
#endif
};
