// Question link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution {
public:
    unordered_set <string> us;
    int res = 0;
    void dfs(string &s, int idx)
    {
        if(us.size() > res)
            res = us.size();
        if(idx >= s.length())
            return;
        string str = "";
        for(int i = idx; i < s.length(); i++)
        {
            str += s[i];
            if(us.find(str) == us.end())
            {
                us.insert(str);
                dfs(s, i+1);
                us.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return res;
    }
};
