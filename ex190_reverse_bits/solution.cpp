class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        auto get_bit = [&n](int k)
        {
            return (n >> k) & 1;
        };
        
        uint32_t copy(0);
        for (uint32_t i = 0; i < 32; ++i)
        {
            copy |= (get_bit(i) << (31 - i));
        }
        return copy;
    }
};