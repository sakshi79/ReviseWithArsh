// Question link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

class Solution {
    long long res;
    void merge(vector<int> &arr, int low, int mid, int high, int diff)
    {
        vector<int> temp(high-low+1);
        int i=low, j=mid+1, k=0;

        //count pairs in merged array
        while(i<=mid && j<=high)
        {
            if(arr[i] <= arr[j]+diff)
            {
                res += high-j+1;
                i++;
            }
            else
                j++;            
        }

        //merge
        i = low, j = mid+1;
        while(i<=mid && j<=high)
        {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while(i<=mid)
            temp[k++] = arr[i++];
        while(j<=high)
            temp[k++] = arr[j++];
        k = 0;
        for(int z = low; z <= high; z++,k++)
            arr[z] = temp[k]; 

    }

    void mergeSort(vector<int> &nums, int start, int end, int diff)
    {
        if(start >= end)
            return;
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid, diff);
        mergeSort(nums, mid+1, end, diff);
        merge(nums, start, mid, end, diff);
    }
    
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        res = 0;
        int n = nums1.size();
        vector<int> nums(n);
        for(int k=0; k<n; k++)
        {
            nums[k] = nums1[k] - nums2[k];
        }
        // Can't sort the whole array because we need i<j pairs, i.e. order matters
        mergeSort(nums, 0, n-1, diff);
        return res;
    }
};
