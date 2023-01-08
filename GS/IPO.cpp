//Question link: https://leetcode.com/problems/ipo/

class Solution {
public:
    /*static bool myCmp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }*/

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector <pair<int,int> > projects;
        for(int i=0; i<n; i++)
        {
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(), projects.end());
        priority_queue <int> pq;

        int ans = 0, i=0;
        while(i<n && k)
        {
            if(projects[i].first <= w) 
            {
                pq.push(projects[i].second);
                i++;
            }
            else{
                if(!pq.empty())
                {
                    w += pq.top();
                    pq.pop();
                    k--;
                }
                else
                    return w;
            }
        }
        while(!pq.empty() && k){
            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};
