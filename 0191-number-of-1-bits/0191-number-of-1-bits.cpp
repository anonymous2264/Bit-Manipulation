class Solution {
public:
    int hammingWeight(int n) {
        int table[256] = {0};
        for (int i = 1; i < 256; i++) {
            table[i] = table[i >> 1] + (i & 1);
        }
        return table[n & 0xFF]
             + table[(n >> 8) & 0xFF]
             + table[(n >> 16) & 0xFF]
             + table[(n >> 24) & 0xFF];
    }
};