// Question link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1, res=0;
        vector <int> temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        
        while(start < n)
        {
            if(temp[start] != nums[start])
                break;
            start++;
        }
        while(end >= start)
        {
            if(temp[end] != nums[end])
                break;
            end--;
        }  
        return end-start+1;
    }
};
