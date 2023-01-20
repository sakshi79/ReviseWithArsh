// Question link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
    int left(int n, int k)
    {
        if(n==1)
            return 0;
        else
            return (findTheWinner(n-1, k) + k-1) % n;
    }
public:
    int findTheWinner(int n, int k) {
        return left(n, k) + 1;
    }
};
