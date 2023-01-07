// Question link: 

class Solution {
    double distance(vector<int> &A, vector<int> &B)
    {
        int x1 = A[0];
        int y1 = A[1];
        int x2 = B[0];
        int y2 = B[1];
        return sqrt( pow((A[0]-B[0]),2) + pow((A[1]-B[1]),2) );
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i=0; i<n; i++)
        {
            unordered_map <double, int> m;
            for(int j=0; j<n; j++)
            {
                m[distance(points[i], points[j])]++;
            }
            for(auto it: m)
                res += it.second*(it.second-1);
        }
        return res;
    }
};
