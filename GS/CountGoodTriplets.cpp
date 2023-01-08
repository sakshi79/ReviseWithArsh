// Question link: https://leetcode.com/problems/count-good-triplets-in-an-array/

class Solution {
    typedef long long ll;
    vector <ll> inv;
    vector <pair<int,int> > v; //vector of indices of int i in nums1, nums2

    void merge(int low, int mid, int high)
    {
        int i = low, j = mid+1;
        while(i<=mid && j<=high)
        {
            if(v[i].first < v[j].first)
            {
                inv[v[i].second] += (j-mid-1);
                i++;
            }
            else
                j++;
        }
        while(i<=mid)
        {
            inv[v[i].second] += (j-mid-1);
            i++;
        }
        sort(v.begin()+low, v.begin()+high+1);
    }

    void mergesort(int low, int high)
    {
        if(low < high)
        {
            int mid = (low+high)/2;
            mergesort(low, mid);
            mergesort(mid+1, high);
            merge(low, mid, high);
        }
    }

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector <int> ind(n);
        for(int i=0; i<n; i++)
        {
            ind[nums1[i]] = i;
        }
        for(int i=0; i<n; i++)
        {
            nums2[i] = ind[nums2[i]];
            v.push_back({nums2[i], i});
        }

        inv.resize(n,0);
        mergesort(0, n-1);

        ll res = 0;
        for(int i=0; i<n; i++)
        {
            ll left = nums2[i] - inv[i];  //number of elements less than nums2[i] towards left
            ll right = (n-i-1) - inv[i];  //number of elements greater than nums2[i] towards right
            res += left*right;
        }
        return res;
    }
};
