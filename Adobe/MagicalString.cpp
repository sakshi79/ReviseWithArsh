// Question link: https://leetcode.com/problems/magical-string/

class Solution {
public:
    int magicalString(int n) {
        if(n <= 2)
            return 1;
        //string aux1 = "122"
        string magic = "122";

        int curr = 2, end = 2;
        while(magic.size() <= n)
        {
            if(magic[curr] == '1' and magic[end] == '2')
            {
                magic += "1";
            }
            else if(magic[curr] == '1' and magic[end] == '1')
            {
                magic += "2";
            }
            else if(magic[end] == '2')
            {
                magic += "11";
            }
            else
            {
                magic += "22";
            }
            curr++;
            end = magic.size() -1;
        }

        int res = 0;
        for(int i=0; i<n; i++)
            if(magic[i] == '1')
                res++;

        return res;
    }
};
