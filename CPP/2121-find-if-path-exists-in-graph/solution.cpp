class Solution {
public:
    bool canReach(int cur,int dest,vector<vector<int>> &adj,vector<int> &visited){
        visited[cur]=1;
        if(cur==dest)   return true;
        for(auto nei:adj[cur]){
            if(!visited[nei]){
                if(canReach(nei,dest,adj,visited))  return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n,0);
        return canReach(source,destination,adj,visited);
    }
};
