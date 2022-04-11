class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::map<int, int> counts;
        for (auto& candidate : candidates) {
            counts[candidate]++;
        }
        
        vector<int> partialSolution;
        vector<vector<int>> solutions;
        backTrack(counts, 0, target, partialSolution, solutions);
        return solutions;
    }
    
    void backTrack(map<int, int>& counts, int sum, int target, vector<int>& partial, vector<vector<int>>& solutions) {
        if (sum == target) {
            solutions.push_back(partial);
            return;
        } else if (sum > target) {
            return;
        }
        
        for (auto& kvp : counts) {
            if (kvp.second == 0) {
                continue;
            }
            
            if (partial.size() > 0 && partial.back() > kvp.first)
                continue;
            
            if (sum + kvp.first > target) 
                break;
            
            partial.push_back(kvp.first);
            kvp.second--;
            backTrack(counts, sum + kvp.first, target, partial, solutions);
            kvp.second++;
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
