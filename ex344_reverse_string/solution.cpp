class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        
        size_t head = 0, tail = s.size() - 1;
        while (head < tail)
        {
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;
            
            head++;
            tail--;
        }
    }
};