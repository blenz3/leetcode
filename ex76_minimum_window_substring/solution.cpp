class Solution {
public:
    
    bool is_substring(std::unordered_map<char, int>& source_counts, std::unordered_map<char, int>& target_counts)
    {
        for (auto& kvp : target_counts)
        {
            if (source_counts[kvp.first] < kvp.second)
                return false;
        }

        return true;
    }
    
    string minWindow(string s, string t) 
    {
        if (s.empty() || t.empty() || t.length() > s.length())
            return "";
        
        std::unordered_map<char, int> character_counts;
        std::unordered_map<char, int> required_character_counts;
        
        for (auto c : t)
        {
            required_character_counts[c]++;
        }
        
        bool legitimate_substring(false);
        int best_left_index(0), best_right_index(INT_MAX);
        
        int left_index(0), right_index(0);
        while (left_index < s.length() || right_index < s.length())
        {
            // If we haven't discovered a legitimate substring then we need to grow our set of counts.
            // We refresh the legitimate substring flag after accumulating a new character
            if (!legitimate_substring && right_index != s.length())
            {
                character_counts[s[right_index++]]++;
                legitimate_substring = is_substring(character_counts, required_character_counts);
            }
            else
            {
                // We have a legitimate substring so let's cache the best result if it is better and then 
                // try to remove from the left
                if (legitimate_substring && right_index - left_index < best_right_index - best_left_index)
                {
                    best_right_index = right_index;
                    best_left_index = left_index;
                }
                character_counts[s[left_index++]]--;
                legitimate_substring = is_substring(character_counts, required_character_counts);
            }
            
        }
        
        if (best_right_index == INT_MAX)
            return "";
        
        return s.substr(best_left_index, best_right_index - best_left_index);
       
    }
};