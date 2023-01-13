// Question link: https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        
        int first = INT_MAX, second = INT_MAX;
        for(int curr: nums)
        {
            if(curr < first)
                first = curr;
            if(curr>first and curr<second)
                second = curr;
            if(curr > second)
                return true;
        }
        return false;
    }
};
