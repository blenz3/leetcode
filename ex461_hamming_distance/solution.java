class Solution {
    public int hammingDistance(int x, int y)
    {
        int count = 0;
        int hammingWeighted = x ^ y;
        for (int i = 0; i < 31; ++i)
        {
            count += ((hammingWeighted & (1 << i)) == 0) ? 0 : 1;
        }

        return count;
    }
}
