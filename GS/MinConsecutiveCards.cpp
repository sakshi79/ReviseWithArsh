// Question link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        int n = cards.size();
        unordered_map <int, int> m;
        for(int i=0; i<n; i++)
        {
        
            if(m.find(cards[i]) != m.end())
            {
                
                int curr = abs(m[cards[i]] - i) + 1;
                res = min(res, curr);
            }
            m[cards[i]] = i;
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
