class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1) {
            return true;
        }
        
        int leftIndex = 0, rightIndex = s.length() - 1;
        while (leftIndex <= rightIndex) {
            while (leftIndex <= rightIndex && !isValidCharacter(s[leftIndex]))
                leftIndex++;
            
            while (rightIndex >= leftIndex && !isValidCharacter(s[rightIndex]))
                rightIndex--;
            
            if (leftIndex > rightIndex) 
                break;
            
            if (::tolower(s[leftIndex]) != ::tolower(s[rightIndex])) {
                return false;
            }
            
            leftIndex++;
            rightIndex--;
        }
        
        return true;
    }
    
    bool isValidCharacter(char c) {
        return ::isdigit(c) || ::isalpha(c);
    }
};
