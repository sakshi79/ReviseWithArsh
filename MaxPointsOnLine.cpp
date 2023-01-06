//Question link: https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)
            return 1;
        int res = 0;
        int slope;
        unordered_map <double, int> m;

        for(int i=0; i<n; i++)
        {
            unordered_map <double, int> m;
            for(int j=i+1; j<n; j++)
            {
                if(i != j)
                {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    if(x2 != x1)
                    {
                        double slope = (1.0*(y2-y1))/(x2-x1);
                        //cout<<slope;
                        m[slope]++;
                    }
                    else
                        m[INT_MAX]++;
                }
            }
            for(auto it: m)
            {
                //cout<<it.first<<" "<<it.second<<endl;
                res = max(res, it.second + 1);
            }
        }
        
        return res;
    }
};
