class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)
        {
            return 1;
        }
        bool sign =true;
        if(dividend>=0 && divisor<0)
        sign=false;
        if(dividend<0 && divisor>0)
        sign=false;
        long n=abs(dividend);
        long d=abs(divisor);
        long ans=0;
        while(n>=d)
        {
            int c=0;
            while(n>=(d<<(c+1)))
            {
                    c++;
            }
            ans=ans+(1<<c);
            n-=(d<<c);
        }
        if(dividend ==INT_MIN && divisor==-1)
        return INT_MAX;
        return sign?ans:-ans;
    }
};