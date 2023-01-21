// Question link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set <string> us;
        int start = 0;
        int end = 0;
        string temp = "";
        while(end < s.length())
        {
            int len = end-start+1;
            if(len<=k)
            {
                temp.push_back(s[end]);
                end++;
            }
            else
            {
                us.insert(temp);
                temp = temp.substr(1, temp.length());
                start++;
            }
        }
        if(temp.length() == k)
            us.insert(temp);
        if(us.size() == pow(2,k))
            return true;
        return false;
    }
};
