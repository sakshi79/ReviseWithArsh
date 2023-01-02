// Question link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        unordered_map <char, int> m;
        int n = s.length()-1;
        int l=0, r=0;

        while(r <= n )
        {
            m[s[r]]++;
            while(m['a'] && m['b'] && m['c'])
            {
                res += (n-r)+1;
                m[s[l]]--;
                l++;
            }
            r++;
        }

        return res;
    }
};
