// Question link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int res = special[0] - bottom;
        int n = special.size();
        if(n==1)
            return max(res, top-special[0]);
        res = max(res, top -special[n-1]);

        for(int i = 1; i < n; i++)
        {
            res = max(res, special[i]-special[i-1]-1);
        }

        return res;
    }
};
