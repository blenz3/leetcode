
vector<vector<int>> removeDupes(const vector<vector<int>>& nums);
void printVector(const vector<int>& v);
bool compareSolutions(const vector<int>& lhs, const vector<int>& rhs);


// Brute Force
//  - For each i,j do a two sum
class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) 
            return vector<vector<int>>{};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        
        int averageRequiredValue = target / 4, prevStartVal = -1, prevEnd = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > averageRequiredValue) {
                break;
            }
            
            for (int j = i + 3; j < nums.size(); ++j) {
                if (nums[j] < averageRequiredValue || (j - i > 3 && nums[j] == nums[i])) {
                    continue;
                }
                
                evaluate4Sum(nums, out, target, i, j);    
            }
            
        }
        
        return removeDupes(out);
    }
    
     void evaluate4Sum(const vector<int>& nums, vector<vector<int>>& out, int64_t target, int start, int end) {
        if (end - start < 3) {
            return;
        }
        
        int64_t partialSum = nums[start] + nums[end];
        int64_t partialComplement = abs(partialSum - target) * ((partialSum > target) ? -1 : 1);
        twoSum(nums, out, partialComplement, start, end);
    }
    
    void twoSum(const vector<int>& nums, vector<vector<int>>& out, int64_t target, int start, int end) {
        int first = start++, last = end--;
        while (start < end) {
            int64_t sum = nums[start] + nums[end];
            if (sum < target) {
                start++;
            } else if (sum > target) {
                end--;
            } else if (sum == target) {
                out.push_back({nums[first], nums[start], nums[end], nums[last]});
                
                // Move the head pointer to the first new value
                while (start < end && nums[start] == nums[start + 1]) 
                    start++;

                // Move the tail pointer to the first new value
                while (start < end && nums[end] == nums[end - 1])
                    end--;
                
                start++, end--;
            }   
        }
    }
    
};

vector<vector<int>> removeDupes(const vector<vector<int>>& nums) {
    vector<vector<int>> out;
    for (auto& candidate : nums) {
        bool isNew = true;
        for (auto& solutions : out) {
            if (compareSolutions(candidate, solutions)) {
                isNew = false;
                break;
            }
        }

        if (isNew) 
            out.push_back(candidate);
    }

    return out;
}

bool compareSolutions(const vector<int>& lhs, const vector<int>& rhs) {
     if (lhs.size() != rhs.size())
        return false;

    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }

    return true;
}

void printVector(const vector<int>& v) {
    printf("[");
    for (auto num : v) {
        printf("%d, ", num);
    }
    printf("]\n");
}
