// Question link: https://leetcode.com/problems/max-area-of-island/

class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int &count)
    {
        vis[x][y] = true;
        count++;
        
        if(x>0 && grid[x-1][y]==1 && !vis[x-1][y])
            dfs(grid, vis, x-1, y, count);
        if(y>0 && grid[x][y-1]==1 && !vis[x][y-1])
            dfs(grid, vis, x, y-1, count);
        if(x<grid.size()-1 && grid[x+1][y]==1 && !vis[x+1][y])
            dfs(grid, vis, x+1, y, count);
        if(y<grid[0].size()-1 && grid[x][y+1]==1 && !vis[x][y+1])
            dfs(grid, vis, x, y+1, count);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<bool>> visited(n, vector<bool>(m,false));
        int area = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    cout<<"here";
                    int curr_area = 0;
                    dfs(grid, visited, i, j, curr_area);
                    area = max(area, curr_area);
                }
            }
        }
        return area;
    }
};
