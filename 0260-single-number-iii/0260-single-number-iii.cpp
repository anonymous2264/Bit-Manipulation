class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall=0;
        for(int num:nums)
        {
            xorall^=num;
        }
        long long diffbit=xorall & (-xorall);
        int x=0;
        for(int num:nums)
        {
        if(num & diffbit)
        {
            x^=num;
        }
        }
        return {x,(int)(xorall^x)};
    }
};