class Solution {
public:
    // General gameplan will be to have two pointers one in string s and one in string t. Since the ordering
    // of characters in s must be preserved within t we can just greedily consume characters from s when they
    // first appear in t. If we reach the end of t and haven't consumed all characters in s then we have shown
    // that this string is not a subsequence. Runs in linear time with constant memory
    bool isSubsequence(string s, string t)
    {
        int s_idx(0), t_idx(0);
        while (s_idx < s.length() && t_idx < t.length())
        {
            if (s[s_idx] == t[t_idx])
            {
                s_idx++;
            }
            
            t_idx++; // always move t one to the right
        }
        
        return (s_idx == s.length());
        
    }
};