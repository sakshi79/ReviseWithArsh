// Question link: https://leetcode.com/problems/maximum-matrix-sum/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int min_ele = INT_MAX, neg = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] < 0)
                    neg++;
                int curr = abs(matrix[i][j]);
                sum += curr;
                min_ele = min(min_ele, curr);
            }
        }

        if(neg%2==0)
            return sum;
        else
            return sum-2*min_ele;
    }
};
