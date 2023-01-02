// Question link: https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int res;
        int sum =0, f = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            f += i*nums[i];
        }
        res = f;
        for(int i=n-1; i>0; i--)
        {
            f += sum - n*nums[i];
            res = max(res, f);
        }
        return res;
    }
};
