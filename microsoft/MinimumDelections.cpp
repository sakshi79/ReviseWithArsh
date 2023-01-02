//Question link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution {
    
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.end());
        int count = 0;
        int HCF = numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++)
            HCF = __gcd(HCF, numsDivide[i]);

        while(!pq.empty())
        {
            int x = pq.top();
            if(HCF%x == 0)
                return count;
            pq.pop();
            count++;
        }
        return -1;
    }
};
