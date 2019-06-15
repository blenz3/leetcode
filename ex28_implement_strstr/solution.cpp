class Solution {
public:
    int strStr(string haystack, string needle)
    {
                
        if ((haystack.empty() && !needle.empty()) || haystack.length() < needle.length())
        {
            return -1; // boundary conditions. no checking needed
        }
        
        if (haystack.empty() || needle.empty())
            return 0;

        int start_idx(0);
        while (start_idx < haystack.length() - needle.length() + 1)
        {
            if (haystack[start_idx] == needle[0] && 0 == ::strncmp(haystack.c_str() + start_idx, needle.c_str(), needle.length()))
            {
                return start_idx;
            }
            
            start_idx++;
        }
        
        return -1;
    }
};