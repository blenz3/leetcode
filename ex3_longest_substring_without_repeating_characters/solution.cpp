class Solution {
public:
    // Optimized (linear time, linear space)
    int lengthOfLongestSubstring(string s) {
        
        std::set<char> observed_characters;    
        int longest_substring(0);
        
        int left(0), right(0);
        
        while (left <= right && right < s.length())
        {
            auto find_it = observed_characters.find(s[right]);
            if (find_it == observed_characters.end())
            {
                observed_characters.insert(s[right++]);
            }
            else
            {
                // we've seen this before
                observed_characters.erase(s[left++]);
            }
            
            longest_substring = std::max(longest_substring, right - left);
        }
        
        return longest_substring;
        
    }
#if 0
    // Brute force (quadratic time, linear space)
    int lengthOfLongestSubstring(string s) {
        
        std::set<char> observed_characters;    
        int longest_substring(0);
        for (int l = 0; l < s.length(); ++l)
        {
            // reset observed characters for the new substring
            observed_characters.clear();
            observed_characters.insert(s[l]);
            for (int r = l + 1; r < s.length(); ++r)
            {
                // keep adding observed characters
                if (observed_characters.find(s[r]) == observed_characters.end())
                {
                    observed_characters.insert(s[r]);
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            // keep track of the longest we've seen so far
            if (observed_characters.size() > longest_substring)
            {
                longest_substring = observed_characters.size();
            }
        }
        
        return longest_substring;
    }
#endif
};