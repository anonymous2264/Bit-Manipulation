class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorval=x^y;
        int c=0;
        while(xorval>0)
        {
            xorval=xorval & (xorval-1);
            c++;
        }
        return c;
    }
};