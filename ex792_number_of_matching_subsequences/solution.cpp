class Solution {
public:
    
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        int count(0);
        
        // Bucket each word according to its first character
        std::vector<std::vector<const char*>> partial_words(26);
        for (auto& word : words)
        {
            if (word.empty())
            {
                count++;
                continue;
            }
            
            partial_words[word[0] - 'a'].push_back(word.c_str());
        }
        
        // Handle collisions with words like aardvark where we need to rebucket it into the
        // same place that it started in
        std::vector<const char*> collisions;
        collisions.reserve(words.size());
        
        // For each character in the input sequence rebucket each next word
        int s_idx(0);
        while (s_idx < S.length())
        {
            auto& bucket = partial_words[S[s_idx] - 'a'];
            
            for (auto& partial_word : bucket)
            {   
                // move to the next character
                partial_word++;
                
                // If we are at a null terminator then capture this one in our count
                if (*partial_word == '\0')
                {
                    count++;
                }
                else if (*partial_word != S[s_idx]) // rebucket to a different bucket
                {
                    partial_words[(*partial_word) - 'a'].push_back(partial_word);
                }
                else
                {
                    collisions.push_back(partial_word);
                }
            }
            
            bucket.swap(collisions);
            collisions.clear();
            
            s_idx++;
        }
        
        return count;
    }
};