class Solution {
public:
    // Strategy
    //  - Take 1 to 3 stones off and if you take off the last stone then you win
    //      - This means you'll always lose at 4, but always win if the remainder is between 1-3
    bool canWinNim(int n) {
        return (n % 4) != 0;
    }
};
