class Solution {
public:
    // See if a portion of a string is a palindrome
    bool isPalindrome(const std::string& s, size_t begin, size_t end)
    {
        if (end - begin < 1)
            return true;
        
        // inspect a character at a time until they cross
        while (end >= begin)
        {
            if (s[begin++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int expand(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    string longestPalindrome(string s) 
    {
        // expand from center O(n^2)
        
        int longest_left(0);
        int longest_right(0);
        for (int i = 0; i < s.length(); ++i)
        {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i + 1);
            
            int max_len = std::max(l1, l2);
            if (max_len > longest_right - longest_left)
            {
                longest_left = i - (max_len - 1) / 2;
                longest_right = i + (max_len / 2);
            }
        }
        
        return s.substr(longest_left, longest_right - longest_left + 1);
        
        
#if 0
        // brute force O(N^3)
        size_t longest_left(0), longest_right(0);
        for (size_t i = 0; i < s.length(); ++i)
        {
            for (size_t j = i; j < s.length(); ++j)
            {
                if (!isPalindrome(s, i, j))
                    continue;
                
                if (j - i > longest_right - longest_left)
                {
                    longest_right = j;
                    longest_left = i;
                }
            }
        }
        
        return s.substr(longest_left, longest_right - longest_left + 1);
#endif
    }
};