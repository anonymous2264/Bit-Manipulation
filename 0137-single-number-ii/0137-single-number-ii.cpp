class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<32;i++)
        {
            int bitmask=0;
            for(int &num:nums)
            {
                bitmask+=(num>>i)&1;
            }
            if(bitmask%3==1)
            result|=(1<<i);
        }
        return result;
    }
};