// Question link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> m;
        for(int x: nums)
        {
            m[x]++;
        }
        map<int,int> m1;
        for(int i: nums)
        {
            if(m[i]==0)
                continue;
            if(m1[i] > 0)
            {
                m1[i]--;
                m1[i+1]++;
                m[i]--;
            }
            else if(m[i]>0 && m[i+1]>0 && m[i+2]>0)
            {
                m[i]--;
                m[i+1]--;
                m[i+2]--;
                m1[i+3]++;
            }
            else
                return false;
        }

        return true;
    }
};
