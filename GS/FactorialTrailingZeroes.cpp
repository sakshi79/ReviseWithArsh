// Question link: https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        if(n<5)
            return res;
        int x = 1;
        while(n/pow(5,x))
        {
            res += n/pow(5,x);
            x++;
        }
        return res;
    }
};
