class Solution {
public:
    
    // Swap odds to the back
    vector<int> sortArrayByParity(vector<int>& nums) {
        int readHead = 0, writeHead = nums.size() - 1;
        while (readHead < writeHead) {
            if (nums[readHead] % 2 == 0) {
                readHead++;
                continue;
            } 
            
            while (readHead < writeHead && nums[readHead] % 2 != 0) {
                swap(nums[readHead], nums[writeHead--]);
            }
            
            readHead++;
        }
        
        return nums;
    }
    
    void swap(int& a, int& b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }
    
#if 0
    // Brute force
    //   - Just create a copy of the array and start writing evens at the front and odds at the end
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evensIdx = 0, oddsIdx = nums.size() - 1;
        vector<int> out(nums.size(), 0);
        for (auto num : nums) {
            if (num % 2 == 0) {
                out[evensIdx++] = num;
            } else {
                out[oddsIdx--] = num;
            }
        }
        return out;
    }
#endif
};
