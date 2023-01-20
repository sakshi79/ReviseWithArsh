// Question link: https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int getPeak(MountainArray &arr, int n)
    {
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if( (mid==0 || arr.get(mid-1) <= arr.get(mid)) && (mid==n-1 || arr.get(mid+1)<=arr.get(mid)) )
                return mid;
            if(mid>0 && arr.get(mid-1)>=arr.get(mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();       
        int peak_ind = getPeak(mountainArr, n);
        
        int l = 0;
        int r = peak_ind;
        int m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (mountainArr.get(m) < target)
                l = m + 1;
            else if (mountainArr.get(m) > target)
                r = m - 1;
            else
                return m;
        }

        l = peak_ind;
        r = n - 1;
        while (l <= r)
        {
            m = (l+r) / 2;
            if (mountainArr.get(m) > target)
                l = m + 1;
            else if (mountainArr.get(m) < target)
                r = m - 1;
            else
                return m;
        }
        return -1;
        
    }

};
