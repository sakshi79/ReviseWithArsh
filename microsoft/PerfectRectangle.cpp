// Question link: https://leetcode.com/problems/perfect-rectangle/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        if(n <= 1)
            return true;
        map <pair<int,int>, int> m;
        
        for(auto rec: rectangles)
        {
            m[{rec[0], rec[1]}]++;
            m[{rec[2], rec[3]}]++;
            m[{rec[0], rec[3]}]--;
            m[{rec[2], rec[1]}]--;
        }

        int count = 0;
        for(auto i: m)
        {
            if(i.second != 0)
            {
                if(i.second==1 || i.second==-1)
                    count++;
                else
                    return false;
            }
        }
        return count==4;
    }
};
