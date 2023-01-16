// Question link: https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
    unordered_map <char,int> mp;
    bool isSubSeq(string &s, string &word, int n)
    {
        int m = word.length();
        int j = 0;
        for(int i=0; i<n and j<m; i++)
        {
            if(s[i] == word[j])
                j++;
        }
        return (j==m);
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        int n = s.length();
        unordered_map <string,int> mp;
        for(string word: words)
            mp[word]++;
        for(auto x: mp)
        {
            string word = x.first;
            if(isSubSeq(s, word, n))
                res += x.second;
        }
        return res;
    }
};
