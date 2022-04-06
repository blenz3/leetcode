class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
    
    bool dfs(vector<int>& arr, int start) {
        // printf("start %d\n", start);
        if (start < 0 || start >= arr.size() || arr[start] == -1)
            return false;
        
        if (arr[start] == 0) {
            return true;
        }
        
        int jump = arr[start];
        arr[start] = -1;
        bool result = dfs(arr, start + jump) || dfs(arr, start - jump);
        return result;
    }
};
