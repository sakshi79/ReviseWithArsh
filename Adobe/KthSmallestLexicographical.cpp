// Question link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

class Solution {
public:
    int findKthNumber(int n, int k) {
        int x = 1;
        while(k > 1)
        {
            long count = 0;
            long diff = 1;
            for(long curr = x; curr <= n; curr*=10)
            {
                count += min(n-curr+1, diff);
                diff *= 10;
            }
            if(k > count)
            {
                k -= count;
                x++;
            }
            else
            {
                k--;
                x*= 10;
            }
        }
        return x;
    }
};
