// Question link: https://leetcode.com/problems/course-schedule/

class Solution {
    bool DFScycle(vector<int> adj[], int s, bool visited[], bool recSt[])
    {
        visited[s] = true;
        recSt[s] = true;
        for(int u: adj[s])
        {           
            if(visited[u] == false)
            {
                if(DFScycle(adj, u, visited, recSt))
                    return true;
            }

            else if(recSt[u] == true)
                return true;
        }
        recSt[s] = false;
        cout<<"here";
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        bool visited[V];
        bool recSt[V];
        for(int i=0; i<V; i++)
        {
            visited[i] = false;
            recSt[i] = false;
        }
        vector<int> adj[V];
        for(auto it: prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
                        
        for(int i=0; i<V; i++)
        {            
            if(visited[i] == false)
                if(DFScycle(adj, i, visited, recSt) == true)
                    return false; // because courses can be done only if no cycle
        }
        return true;
    }
};
