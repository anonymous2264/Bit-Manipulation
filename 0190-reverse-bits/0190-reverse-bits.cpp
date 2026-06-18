class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
   int result = 0;
        n = (n >> 16) | (n << 16);
        // Swap 8-bit groups
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        // Swap 4-bit nibbles
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        // Swap 2-bit pairs
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        // Swap adjacent bits
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};