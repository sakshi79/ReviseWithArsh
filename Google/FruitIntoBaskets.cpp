// Question link: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // count number of trees of two most commom types. Those trees must be continuous
        // Effectively length of longest subarray with maximum 2 distinct types(integers)
        int res = 0;
        int n = fruits.size();
        unordered_map <int,int> baskets;
        int start = 0;
        for(int i = 0; i<n; i++)
        {
            baskets[fruits[i]]++;

            while(baskets.size() > 2)
            {
                baskets[fruits[start]]--;
                if(baskets[fruits[start]] == 0)
                    baskets.erase(fruits[start]);
                start++;
            }

            res = max(res, i-start+1);
        }

        return res;       
    }
};
