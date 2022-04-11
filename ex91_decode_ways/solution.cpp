
class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return backTrack(s, 0, memo);
    }
    
    void print(const vector<int>& v) {
        printf("[");
        for (auto x : v) {
            printf("%d, ", x);
        }
        printf("]\n");
    }
    
    int backTrack(const std::string& s, int index, vector<int>& memo) {
        if (index == s.length()) {
            return 1;
        }
        
        if (memo[index] != -1) {
            return memo[index];
        } 
            
        
        int sum = 0;
        if (s[index] == '0') {
            return sum;
        }
        
        // Always can take a 1 step since we've ruled out zero
        sum += backTrack(s, index + 1, memo);    
        

        // Check for valid 2 step
        //   - Cannot be the end of the string
        //   - number has to be between 1..26 inclusive
        bool validTwoStep = (
            (index + 1 != s.length()) &&
            (s[index] < '3') &&
            (s[index] == '1' || s[index] == '2' && s[index + 1] < '7')
        );
        if (validTwoStep) {
            sum += backTrack(s, index + 2, memo);
        } 
        
        memo[index] = sum;
        
        return sum;
    }
};
