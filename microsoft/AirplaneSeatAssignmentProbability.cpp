// Question link: https://leetcode.com/problems/airplane-seat-assignment-probability/
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
            return double(1);
        else
            return double(1.0/2);
    }
};
