// Question link: https://leetcode.com/problems/top-k-frequent-words/

class Solution {
    static bool myCmp(pair<string,int> a, pair<string,int> b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector <string> res;
        int n = words.size();
        unordered_map <string,int> h;
        for(auto word: words)
            h[word]++;
        vector <pair<string,int> > freq;
        for(auto it: h)
            freq.push_back({it.first, it.second});
        sort(freq.begin(), freq.end(), myCmp);
        for(int i=0; i<k; i++)
            res.push_back(freq[i].first);
        return res;
    }
};
