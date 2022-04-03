class Solution {
public:
     vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n * 2, 0, n, result);
        return result;
    }
    
    void generate(string s, int targetLength, int openCount, int remainingOpen, vector<string> & result){
        if (s.length() == targetLength){
            result.push_back(s);
            return;
        }
        if (remainingOpen > 0){
            generate(s + '(', targetLength, openCount+1, remainingOpen-1, result);
        }
        if (openCount > 0){
            generate(s + ')', targetLength, openCount-1, remainingOpen, result);
        }
    }
    
#if 0
    // Brute force (recursion)
    //  - In case of n == 1 we return ( and )
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n * 2, result);
        return result;
    }
    
    void generate(string s, int targetLength, vector<string> & result){
        if(s.length() == targetLength){
            if(isValid(s)) 
                result.push_back(s);
            return;
        }
        generate(s + '(', targetLength, result);
        generate(s + ')', targetLength, result);
    }

    // Brute Force (iterative)
    //   - Generate every possible string including n ( and n ) 
    //   - Validate if they are good
    //   - Add to our output
    //   - Runtime 2^n 
    //   - Space 2^n
    vector<string> generateParenthesis(int n) {
        string s(n * 2, '(');
        vector<string> possibleSolutions = {s}, current;
        for (int i = 0; i < n * 2; ++i) {
            for (auto str : possibleSolutions) {
                current.push_back(str);
                str[i] = ')';
                current.push_back(str);
                
            }
            
            possibleSolutions = current;
            current.clear();
        }
        
        for (auto& s : possibleSolutions) {
            if (isValid(s))
                current.push_back(s);
        }
        
        return current;
    }
#endif
    
    bool isValid(const std::string& s) {
        int openCount(0);
        for (auto c : s) {
            if (c == '(')
                openCount++;
            else 
                openCount--;
            
            if (openCount < 0)
                return false;
        }
        
        return (openCount == 0);
    }

};
