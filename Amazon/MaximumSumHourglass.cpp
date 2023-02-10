// Question link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i=0; i<n-2; i++)
        {
            for(int j=1; j<m-1; j++)
            {
                int sum = grid[i][j-1] + grid[i][j] + grid[i][j+1] + grid[i+1][j]
                + grid[i+2][j-1] + grid[i+2][j] + grid[i+2][j+1];

                res = max(res, sum);
            }
        }
        return res;
    }
};
