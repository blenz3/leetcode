class Solution {
public:
    
    // stack strategy
    //   - open parens go onto the stack
    //   - close parens pop them off
    //   - values in the stack will be indices for starts
    int longestValidParentheses(const std::string& s) {
        int longest(0);
        stack<int> opens;
        opens.push(-1);
        
        for (int i = 0 ; i < s.length(); ++i) {
            if (s[i] == '(') {
                opens.push(i);
            } else {
                auto top = opens.top();
                opens.pop();
                if (opens.empty()) {
                    opens.push(i);
                } else {
                    longest = std::max(longest, i - opens.top());
                }
            }
            
        }
        
        return longest;
    }
    
#if 0
    // Better than brute force
    //  - For each character from 0..n check for validity until we know it is no longer valid
    int longestValidParentheses(const std::string& s) {
        int longest(0);
        int i = 0;
        while (i < s.length() && longest < s.length() - i) {
            int opens(0), sequenceLength(1);
            for (int j = i; j < s.length(); ++j) {
                opens += (s[j] == '(') ? 1 : -1;
                if (opens == 0) {
                    longest = std::max(longest, j - i + 1);
                    sequenceLength = j - i + 1;
                } else if (opens < 0) {
                    break;
                }
            }
            
            if (opens == 0) {
                longest = std::max(longest, (int)s.length() - i);
            }
            i += sequenceLength;
        }
        
        return longest;
    }
    
    // Brute Force
    //  - Check validity for each i, j
    //  - Runtime N^3
    //  - Space constant
    int longestValidParentheses(string s) {
        int longest(0);
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                if (isValid(s, i, j)) 
                    longest = std::max(longest, j - i + 1);
                    
            }
        }
        return longest;
    }
    
    bool isValid(const std::string& s, int start, int end) {
        if (start >= end) {
            return false;
        }
        
        int opens(0);
        for (int i = start; i <= end; ++i) {
            opens += (s[i] == '(') ? 1 : -1;
            if (opens < 0) {
                return false;
            }
        }
        
        return (opens == 0);
    }
#endif
};
