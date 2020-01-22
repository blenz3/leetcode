class Solution {
public:
    // 2 ptrs with one at start and one at end and walk each until
    // they cross swapping vowels as we go (O(n) time, O(1) space)
    string reverseVowels(string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int startIdx = 0, endIdx = s.length() - 1;
        while (startIdx < endIdx) {
            while (startIdx < endIdx && !isVowel(s[startIdx])) {
                startIdx++;
            }
            
            while (startIdx < endIdx && !isVowel(s[endIdx])) {
                endIdx--;
            }
            
            if (!isVowel(s[startIdx]) || !isVowel(s[endIdx]))
                break;
            
            auto tmp = s[startIdx];
            s[startIdx] = s[endIdx];
            s[endIdx] = tmp;
            startIdx++;
            endIdx--;
        }
        
        return s;
    }
    
#if 0
    // Straight forward copy of each vowel into a stack
    // and then swapping voewls with the top of the stack
    // (O(n) time, O(n) space)
    string reverseVowels(string s) {
        std::stack<char> vowels;
        for (auto c : s) {
            if (isVowel(c)) {
                vowels.push(c);
            }
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                char vowel = vowels.top();
                vowels.pop();
                s[i] = vowel;
            }
        }
        
        return s;
    }
#endif
    
private:
    bool isVowel(char c) {
        
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
};

