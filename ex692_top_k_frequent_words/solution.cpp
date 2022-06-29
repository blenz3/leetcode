class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, size_t> wordCounts;
        for (auto& word : words) {
            wordCounts[word]++;
        }
        
        priority_queue<pair<size_t, string>, vector<pair<size_t, string>>, Compare> q;
        for (auto& kvp : wordCounts) {
            q.push(make_pair(kvp.second, kvp.first));
        }

        for (int i = 0; i < k; ++i) {
            auto top = q.top();
            words[i] = top.second;
            q.pop();
        }
        
        words.erase(words.begin() + k, words.end());
        
        return words;
    }
    
    
private:
    
    struct Compare {
        bool operator()(const pair<size_t, string>& lhs, const pair<size_t, string>& rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second > rhs.second;
            }
            return lhs.first < rhs.first;
        }
    };
};
