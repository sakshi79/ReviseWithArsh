// Question link: https://leetcode.com/problems/most-profitable-path-in-a-tree/

class Solution {
public:
    int maxAmountA(vector<vector<int>> &graph, int curr, int parent, int timeA, vector<int> &amount, vector<int> &timeB)
    {
        int currCost;
        if(timeA > timeB[curr]) //Alice reached there after Bob so gate was already opened
            currCost = 0;
        else if(timeA == timeB[curr]) //Reached at same time
            currCost = amount[curr]/2;
        else
            currCost = amount[curr];
        
        int AddCost = INT_MIN;
        for(int child: graph[curr])
        {
            if(child == parent)
                continue;
            AddCost = max(AddCost, maxAmountA(graph, child, curr, timeA+1, amount, timeB));
        }
        if(AddCost == INT_MIN)
            AddCost = 0;
        return AddCost + currCost;
    }

    void find_parent(vector<vector<int>> &graph, int curr, int parent, vector<int> &par)
    {
        par[curr] = parent;
        for(int child: graph[curr])
            if(child != parent)
                find_parent(graph, child, curr, par);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector <int> par(n, -1);
        vector <int> timeB(n, n+1);
        vector <vector<int> > graph(n);
        for(auto edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        find_parent(graph, 0, -1, par);
        int bob_time = 0;
        while(bob != 0)
        {
            timeB[bob] = bob_time;
            bob_time++;
            bob = par[bob];
        }

        return maxAmountA(graph, 0, -1, 0, amount, timeB);
    }
};
