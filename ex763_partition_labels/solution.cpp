class Solution {
public:
    vector<int> partitionLabels(string S)
    {
        // constant time, space
        
        // get the end positions for each character
        int character_indexes[26];
        ::memset(character_indexes, 0, sizeof character_indexes);
        for (int i = 0; i < S.length(); ++i)
        {
            character_indexes[S[i] - 'a'] = i;
        }
        
        std::vector<int> out;
        
        int partition_begin(0), partition_end(0);
        for (int i = 0; i < S.length(); ++i)
        {
            // Get the max partition for this character
            partition_end = std::max(partition_end, character_indexes[S[i] - 'a']);
            if (i == partition_end)
            {
                out.push_back(partition_end - partition_begin + 1);
                partition_begin = i +1;
            }
        }
        
        return out;
        
        
    }
};