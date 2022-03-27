class Solution {
public:
    // Strategy
    //  - Walk the string with two characters at a time and find duplicates
    //  - Copy the non-duplicate values to a different string
    //. - Continue the process until the results of walking the string results 
    //.   in no things being removed
    string removeDuplicates(string s) {
        if (s.length() < 2) {
            return s;
        }
        
        stack<char> cs;
        for (auto c : s) {
            if (cs.empty() || cs.top() != c) {
                cs.push(c);
            } else {
                cs.pop();
            }
        }
        
        string out(cs.size(), '\0');
        int insertIdx = cs.size() - 1;
        while (!cs.empty()) {
            out[insertIdx--] = cs.top();
            cs.pop();
        }
        
        return out;
    }
};
