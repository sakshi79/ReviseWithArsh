// Question link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        // Creating adj list
        for(int i=0; i<roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<ll> time(n, LONG_MAX); //Time to reach node from source(i.e. 0)
        time[0] = 0;
        vector<ll> way(n, 0); // Number of ways to reach node in shortest time
        way[0] = 1;

        //Priority Queue for selecting nodes with minimum time first
        priority_queue <pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            ll currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto it: adj[currNode])
            {
                int adjNode = it.first;
                int weight = it.second;
                if(currTime + weight < time[adjNode])
                {
                    time[adjNode] = currTime + weight;
                    pq.push({time[adjNode],adjNode});
                    way[adjNode] = way[currNode]%mod;
                }
                else if(currTime + weight == time[adjNode])
                    way[adjNode] = (way[adjNode] + way[currNode])%mod;
            }
        }

        return way[n-1];
    }
};
