// Question link: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
    pair<int,int> direction[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        if(visited[x][y] || grid[x][y])
            return true;

        if(x==grid.size()-1 || x==0 || y==grid[0].size()-1 || y==0)
            return false;

        visited[x][y] = 1;

        bool left = dfs(x-1, y, grid, visited);
        bool right = dfs(x+1, y, grid, visited);
        bool up = dfs(x, y-1, grid, visited);
        bool down = dfs(x, y+1, grid, visited);
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> visited(n, vector<int>(m,0));
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 0)
                {
                    if(dfs(i, j, grid, visited))
                        res++;
                }
            }
        }
        return res;
    }
};
