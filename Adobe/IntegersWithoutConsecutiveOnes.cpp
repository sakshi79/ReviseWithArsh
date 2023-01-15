// Question link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

class Solution {
public:
    int findIntegers(int n) {
        int res = 0;
        vector <int> dpZero(32), dpOne(32), dp(32);
        dpZero[0] = dp[0] = 1;
        for(int i=1; i<32; i++)
        {
            dpOne[i] = dpZero[i-1];
            dpZero[i] = dpZero[i-1] + dpOne[i-1];
            dp[i] = dpZero[i] + dpOne[i];
        }
        int prev_bit = -1;
        for(int k = 30; k>=0; k--)
        {
            int bit = (n>>k)&1;
            if(bit == 1)
            {
                res += dp[k];
                if(prev_bit == 1)
                    return res;
            }
            prev_bit = bit;
        }
        return res+1;
    }
};
