class Solution {
public:
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
};