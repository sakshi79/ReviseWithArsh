// Question link: https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    vector <int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector <int> dup = original;
        int n = dup.size();
        for(int i=0; i<n; i++)
        {
            int ind = rand()%n;
            swap(dup[ind], dup[i]);
        }
        return dup;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
