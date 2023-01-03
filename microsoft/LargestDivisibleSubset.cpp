// Question link: https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            hash[i] = i;
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && dp[i] < dp[j]+1)
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector <int> res;
        res.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }
        return res;
    }
};
