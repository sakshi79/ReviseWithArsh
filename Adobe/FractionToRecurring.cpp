// Question link: https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int n = numerator, d = denominator;
        if(n==0)
            return "0";
        string res = "";
        if(n<0 ^ d<0)
            res += "-";
        n = abs(n);
        d = abs(d);
        long long q = n/d;
        long long rem = n%d;
        res += to_string(q);
        if(rem == 0)
            return res;

        res += ".";
        string dec = "";
        unordered_map <int,int> m;

        while(rem)
        {
            if(m.find(rem) != m.end())
            {
                int ind = m[rem];
                string repeating = dec.substr(ind);
                dec.erase(ind);
                dec += '('+repeating+")";
                break;
            }
            else
            {
                m[rem] = dec.size();
                dec += to_string(rem*10/d);
                rem = (rem*10)%d;
            }
        }

        return res+dec;        
    }
};
