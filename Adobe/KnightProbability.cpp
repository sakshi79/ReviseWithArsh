// Question link: https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
    double dp[25][25][101];
    double knight(int n, int k, int row, int col)
    {
        if(row < 0 || col < 0 || row >= n || col >= n)
            return 0.0;
        
        if(k == 0)
            return 1.0;

        if(dp[row][col][k])
            return dp[row][col][k];
        //Got TLE without DP
        
        double sum = knightProbability(n, k-1, row+2, col+1) + knightProbability(n, k-1, row+1, col+2)
            + knightProbability(n, k-1, row-2, col+1) + knightProbability(n, k-1, row+1, col-2)
            + knightProbability(n, k-1, row-1, col+2) + knightProbability(n, k-1, row-1, col-2)
            + knightProbability(n, k-1, row+2, col-1) + knightProbability(n, k-1, row-2, col-1);

        return dp[row][col][k] = sum/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        return knight(n, k, row, column);
    }
};
