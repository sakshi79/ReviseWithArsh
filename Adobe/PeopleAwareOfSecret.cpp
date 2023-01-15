// Question link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution {
    typedef long long ll;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;

        vector<ll> people(n, 0);
        people[0] = 1;

        for(int i=0; i<n; i++)
        {
            if(people[i] == 0)
                continue;
            
            //People who know by ith day
            for(int j=i+delay; j<n and (j-i < forget); j++)
            {
                people[j] += people[i];
                people[j] = people[j]%mod;
            }
        }

        //Peple who remember till nth day
        ll res = 0;
        for(int i=n-1; i >= n-forget; i--)
        {
            res += people[i];
            res = res%mod;
        }
        return res;
    }
};
