static const std::unordered_set<char> VOWELS = {
    'a', 'e', 'i', 'o', 'u'  
};

class Solution {
public:
    string removeVowels(string s) {
       
        s.erase(
            std::remove_if(
                s.begin(), 
                s.end(), 
                [](const char c) { 
                    return VOWELS.find(c) != VOWELS.end(); 
                }
            ),
            s.end()
        );
        return s;
        
#if 0
        string out;
        for (auto c : s) {
            if (VOWELS.find(c) != VOWELS.end())
                continue;
            
            out.push_back(c);
        }
        
        return out;
#endif 
    }
};
