class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<bool> used;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            used.push_back(false);
        }
        
        vector<int> path(k, -1);
        vector<vector<int>> solutions;
        permute(k, nums, used, path, solutions);
        return solutions;
    }
    
    void permute(int k, const vector<int>& numbers, vector<bool>& used, vector<int>& path, vector<vector<int>>& solutions) {
        if (k == 0) {
            solutions.push_back(path);
            return;
        }
        
        for (int i = 0; i < numbers.size(); ++i) {
            // Only add numbers that have not yet been added
            if (used[i])
                continue;
  
            // Only add numbers in ascending order 
            int pathIndex = path.size() - k;
            if (pathIndex != 0 && path[pathIndex - 1] > numbers[i])
                continue;
            
            path[pathIndex] = numbers[i];
            used[i] = true;
            permute(k - 1, numbers, used, path, solutions);
            used[i] = false;
        }
    }
};
