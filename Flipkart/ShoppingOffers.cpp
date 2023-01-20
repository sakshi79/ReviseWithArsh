// Question link: https://leetcode.com/problems/shopping-offers/

class Solution {
public:
    map <vector<int>, int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp[needs] > 0)
            return dp[needs];

        int cost = 0;
        for(int i=0; i < needs.size(); i++)
        {
            cost += needs[i]*price[i];
        }
        
        for(auto offer: special)
        {
            vector <int> need = needs;
            bool check = true;
            for(int i=0; i<needs.size(); i++)
            {
                need[i] -= offer[i];
                if(need[i] < 0)
                    check = false;
            }
            if(check)
                cost = min(cost, offer[offer.size()-1] + shoppingOffers(price, special, need));
        }

        return dp[needs] = cost;

    }
};
