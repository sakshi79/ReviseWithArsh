// Question link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].length();
        vector <int> res;
        for(auto q: queries)
        {
            vector <pair<string,int>> v;
            for(int i=0; i<n; i++)
            {
                v.push_back({nums[i].substr(m-q[1]), i});
            }
            sort(v.begin(), v.end());
            res.push_back(v[q[0]-1].second);
        }
        return res;
    }
};
