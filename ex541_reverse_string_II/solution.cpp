class Solution {
public:
    string reverseStr(string& s, int k) {
        for (int group = 0; group < s.length(); group += (2 * k)) {
            if (s.length() - group < k) 
                reverse(s, group, s.length() - 1);
            else
                reverse(s, group, group + k - 1);
        }
        
        return s;
    }
    
    void reverse(string& s, int start, int end) {
        while (start <= end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++, end--;        
        }
    }
};
