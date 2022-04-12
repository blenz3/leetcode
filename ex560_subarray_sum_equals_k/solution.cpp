class Solution {
public:
    
    void print(const vector<int>& nums) {
        printf("[");
        for (auto x : nums) {
            printf("%d, ", x);
        }
        printf("]\n");
    }
    
    
    // Best strategy
    int subarraySum(vector<int>& nums, int k) {
        
        // Create a hash table and preload a zero so a complement will always find it
        unordered_map<int, int> counts;
        counts[0]++;
        
        int sum(0), count(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (counts[sum - k])
                count += counts[sum - k];
            
            ++counts[sum];
        }
        return count;
        
    }
    
#if 0
    // Optimized strategy - Time limit exceeded
    //      - Get sums so far across the array. Difference between sum(x) and sum(x + 2) is the sum
    //        from x to x + 2
    //      - quadratic time
    //      - constant space
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        
        int sum(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            nums[i] = sum;
        }
        
        // print(nums);
        
        int count(0);
        for (int i = 0; i < nums.size(); ++i) {
            // Check all the combinations 
            for (int j = i; j < nums.size(); ++j) {
                if (i == 0 && nums[j] == k) {
                    count++;
                } else if (i != 0 && nums[j] - nums[i - 1] == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
#endif 
    
#if 0
    // Brute Force
    //  - For each i, j, sum it up and see if it equals k
    //  - Runtime quadratic
    //  - Space constant
    int subarraySum(vector<int>& nums, int k) {
        int count(0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += nums[k];
                }
                
                if (sum == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
#endif
};
