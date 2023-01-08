// Question link: https://leetcode.com/problems/maximum-points-in-an-archery-competition/

class Solution {
    vector <int> bobArrows;
    int maxScore = 0;

    void help(vector<int> &aliceArrows, vector<int> &bob, int currMax, int currArrows, int ind)
    {
        if(currArrows==0 || ind<0)
        {
            if(maxScore < currMax)
            {
                maxScore = currMax;
                bobArrows = bob;
            }
            return;
        }
        if(ind == 0)
        {
            bob[ind] = currArrows;
            help(aliceArrows, bob, currMax+ind, 0, ind-1);
            bob[ind] = 0;
            return;
        }
        if(currArrows >= (aliceArrows[ind]+1))
        {
            bob[ind] = aliceArrows[ind] + 1;
            help(aliceArrows, bob, currMax+ind, currArrows-(aliceArrows[ind]+1), ind-1);
            bob[ind] = 0;
        }
        help(aliceArrows, bob, currMax, currArrows, ind-1);

    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> bob(n, 0);
        help(aliceArrows, bob, 0, numArrows, 11);
        return bobArrows;
    }
};
