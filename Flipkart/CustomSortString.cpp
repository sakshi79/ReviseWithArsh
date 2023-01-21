// Question link: https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map <char, int> m;
        string res = "";
        for(auto x: s)
            m[x]++;
        for(auto x: order)
        {
            while(m[x] > 0)
            {
                res += x;
                m[x]--;
            }
        }

        for(auto it: m)
        {
            int cnt = it.second;
            for(int i=0; i<cnt; i++)
                res += it.first;
        }

        return res;
    }
};
