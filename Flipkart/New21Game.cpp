// Question link: https://leetcode.com/problems/new-21-game/

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // 'n': max sum we desire
        if(k==0 || k+maxPts-1<=n)
            return 1;
        double dp[n+1];
        dp[0] = 1;
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            if(i < k)
                sum += dp[i];
            if(i >= maxPts)
                sum -= dp[i-maxPts];

            dp[i+1] = (double)sum/maxPts;
        }

        double res = 0;
        for(int i=k; i<=n; i++)
            res += dp[i];
        return res;
    }
};
