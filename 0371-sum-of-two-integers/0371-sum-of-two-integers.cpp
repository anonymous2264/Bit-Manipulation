class Solution {
public:
    int getSum(int a, int b) {
          while (b != 0) {
            int carry = (a & b) << 1;  // Carry: bits where both are 1, shifted left
            a = a ^ b;                 // Sum without carry: XOR
            b = carry;                 // Process remaining carry in next iteration
        }
        return a;
    }
};