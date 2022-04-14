class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (::abs((int)s.length() - (int)t.length()) > 1) {
            return false;
        }
        
        if (s.length() == t.length()) {
            return (replacementsRequired(s, t) == 1);
        } else if (s.length() > t.length()) {
            return (insertsRequired(t, s) == 1) || (deletesRequired(s, t) == 1);
        } else {
            return insertsRequired(s, t) == 1 || (deletesRequired(t, s) == 1);
        }
    }
    
    int replacementsRequired(const string& s, const string& t) {
        int updates(0);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[i])
                updates++;
        }
        
        return updates;
    }
    
    int deletesRequired(const string& s, const string& t) {
        // Assume s is longer than t
        if (s.empty())
            return t.length();
        
        
        int inserts(0);
        int sIdx = 0, tIdx = 0;
        while (sIdx < s.length() && tIdx < t.length()) {
            if (s[sIdx] != t[tIdx]) {
                inserts++;
                sIdx++;
            } else {
                sIdx++;
                tIdx++;
            }
        }
        if (sIdx != s.length() || tIdx != t.length()) {
            inserts += t.length() - tIdx;
        }
        
        // printf("deletesRequired '%s' -> '%s' %d\n", s.c_str(), t.c_str(), inserts);
        return inserts;
    }
    
    int insertsRequired(const string& s, const string& t) {
        if (s.empty())
            return t.length();
        
        
        int inserts(0);
        int sIdx = 0, tIdx = 0;
        while (sIdx < s.length() && tIdx < t.length()) {
            if (s[sIdx] != t[tIdx]) {
                inserts++;
                sIdx++;
            } else {
                sIdx++;
                tIdx++;
            }
        }
        if (sIdx != s.length() || tIdx != t.length()) {
            inserts += t.length() - tIdx;
        }
        
        // printf("insertsRequired '%s' -> '%s' %d\n", s.c_str(), t.c_str(), inserts);
        return inserts;
    }
};
