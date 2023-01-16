// Question link: https://leetcode.com/problems/minimum-genetic-mutation/
 
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> sets;
        for (auto& s : bank) {
            sets.insert(s);                
        }
        vector<char> genes = {'A', 'G', 'C', 'T'};
        int res = 0;
        queue<string> q;
        q.push(startGene);
        while(!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                string s = q.front();
                q.pop();
                if (s == endGene) {
                    return res;
                }
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (genes[j] != s[i]) {
                            char tmp = s[i];
                            s[i] = genes[j];
                            if (sets.count(s)) {
                                sets.erase(s);
                                q.push(s);
                            }
                            s[i] = tmp;
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
