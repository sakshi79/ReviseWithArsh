// Question link: https://leetcode.com/problems/longest-happy-prefix/

class Solution {
    int fillLPS(string str)
    {
        int n = str.length(), len=0;
        int lps[n];
        for(int i=0; i<n; i++)
            lps[i] = 0;
        //lps[0] = 0;
        int i = 1;
        while(i < n)
        {
            if(str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                    len = lps[len-1];
            }
        }
        return lps[n-1];
    }
public:
    string longestPrefix(string s) {
        int len = fillLPS(s);
        return s.substr(0, len);
    }
};
