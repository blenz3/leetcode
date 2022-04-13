static const unordered_map<char, char> STROBOGRAMMATIC_CHARACTERS = {
    {'1', '1'},
    {'6', '9'},
    {'8', '8'},
    {'9', '6'},
    {'0', '0'}
};

class Solution {
public:
    
    
    bool isStrobogrammatic(const string& num) {
        string inverted;
        for (int i = num.length() - 1; i >= 0; --i) {
            auto find = STROBOGRAMMATIC_CHARACTERS.find(num[i]);
            if (find == STROBOGRAMMATIC_CHARACTERS.end())
                return false;
            
            inverted.push_back(find->second);
        }

        return inverted == num;
    }
};
