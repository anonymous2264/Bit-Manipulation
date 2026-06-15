class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {

        long long evenA = 0, oddA = 0;
        long long evenB = 0, oddB = 0;
        long long evenC = 0, oddC = 0;

        for (int x : a) {
            if (__builtin_popcount(x) % 2)
                oddA++;
            else
                evenA++;
        }

        for (int x : b) {
            if (__builtin_popcount(x) % 2)
                oddB++;
            else
                evenB++;
        }

        for (int x : c) {
            if (__builtin_popcount(x) % 2)
                oddC++;
            else
                evenC++;
        }

        return evenA * evenB * evenC +
               evenA * oddB * oddC +
               oddA * evenB * oddC +
               oddA * oddB * evenC;
    }
};
