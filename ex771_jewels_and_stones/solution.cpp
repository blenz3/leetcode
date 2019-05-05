class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // Game plan is to basically crawl the input stones (S) and see if they are jewels
        
        std::unordered_set<char> jewels(J.begin(), J.end());
        
        int num_jewels(0);
        for (char stone : S)
        {
            if (jewels.find(stone) != jewels.end())
            {
                num_jewels++;
            }
        }
        
        return num_jewels;
    }
};