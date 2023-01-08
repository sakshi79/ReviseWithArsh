// Question link: https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution {
    int reverse(int num)
    {
        int rev = 0;
        while(num > 0)
        {
            rev = rev*10 + num%10;
            num /= 10;
        }
        return rev;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9+7;
        long res = 0;
        int n = nums.size();
        vector<int> v(n, 0);
        unordered_map <int, int> m;
        for(int i=0; i<n; i++)
        {
            v[i] = nums[i] - reverse(nums[i]);
            m[v[i]]++;
        }

        for(auto it: m)
        {
            long cnt = it.second;
            if(cnt >= 2)
            {
                res += (cnt*(cnt-1))/2; //Formula by sum of A.P. for (n-1 + n-2 + ....0)
            }

        }
        
        return res%mod;
    }
};
