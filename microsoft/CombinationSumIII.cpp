// Question link: https://leetcode.com/problems/combination-sum-iii/

class Solution {
    vector <vector <int> > res;
    void try_combs(vector <int> &combination, int start, int k, int n)
    {
        if(k==combination.size() && n==0)
        {
            res.push_back(combination);
            return;
        }
        
        for(int i=start; i<10; i++)
        {
            combination.push_back(i);
            try_combs(combination, i+1, k, n-i);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> combination;
        try_combs(combination, 1, k, n);
        return res;
    }
};
