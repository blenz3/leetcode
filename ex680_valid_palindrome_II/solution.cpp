class Solution {
public:
    bool validPalindrome(string s) {
        if (s.length() < 2) 
            return true;
        
        int start = 0, end = s.length() - 1;
        while (start <= end) { 
            // Once we encounter a bad character continue to attempt to
            // scan for a palindrome with the exclusion of the first
            // character and then a separate scan excluding the last
            if (s[start] != s[end]) {
                return checkPalindromeRange(s, start + 1, end) || checkPalindromeRange(s, start, end - 1);
            }
            
            start++, end--;
        }
        
        return true;
    }
    
    bool checkPalindromeRange(const std::string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            
            start++, end--;
        }
        return true;

    }
};
