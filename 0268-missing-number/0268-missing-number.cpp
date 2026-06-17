class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorVal = 0;

        // XOR all indices [1, n] and all array elements
        for (int i = 0; i < n; i++) {
            xorVal ^= (i + 1) ^ nums[i];
        }

        return xorVal;
    }
};