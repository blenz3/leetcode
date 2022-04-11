static const int MAX_SIZE = 200;



class Solution {
public:
    // Strategy
    //  - Sort the input and since they are unique we should be able to binary search for complements
    //  - We only care about prime numbers since we can just mod by them
    // Brute Force
    //  - For each candidate we then can see if it exists in the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        
        vector<int> partials;
        vector<vector<int>> solutions;
        backTrack(candidates, 0, 0, target, partials, solutions);
        return solutions;
    }
    
    void backTrack(const vector<int>& candidates, int index, int sum, int target, vector<int>& partial, vector<vector<int>>& solutions) {
        
        if (sum == target) {
            solutions.push_back(partial);
            return;
        } else if (sum > target) {
            return;
        }
        
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            partial.push_back(candidates[i]);
            backTrack(candidates, i, sum + candidates[i], target, partial, solutions);
            partial.erase(--partial.end());
        }
    }
             
    void printVector(const vector<int>& nums) {
        printf("[");
        for (auto num : nums) {
            printf("%d, ", num);
        }
        printf("]\n");
    }
    
};
