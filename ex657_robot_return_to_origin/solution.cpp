class Solution {
public:
    // Gameplan - count the total number of moves in each direction. If up == down and left == right then
    // we know that the robot has returned to its start position
    bool judgeCircle(string moves)
    {
        int up(0), down(0), left(0), right(0);
        for (auto move : moves)
        {
            if (move == 'U')
                up++;
            else if (move == 'D')
                down++;
            else if (move == 'R')
                right++;
            else if (move == 'L')
                left++;
        }
        
        return (up == down && left == right);
        
        
    }
};