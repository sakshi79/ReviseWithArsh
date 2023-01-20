// Question link: https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector <int> res;
        unordered_map <int,int> h;
        for(int code: barcodes)
            h[code]++;
        
        priority_queue <pair<int,int>> pq;
        for(auto it: h)
            pq.push({it.second, it.first});
        while(!pq.empty())
        {
            auto curr1 = pq.top();
            pq.pop();
            res.push_back(curr1.second);
            curr1.first--;
            if(!pq.empty())
            {
                auto curr2 = pq.top();
                pq.pop();
                res.push_back(curr2.second);
                curr2.first--;
                if(curr2.first > 0)
                    pq.push(curr2);
            }
            if(curr1.first > 0)
                pq.push(curr1);
        }
        
        return res;
    }
};
