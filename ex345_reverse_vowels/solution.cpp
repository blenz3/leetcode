class Solution {
public:
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
    
private:
    bool isVowel(char c) {
        
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
};

