class Solution {
public:
    bool hasCycle(int i,vector<int> &visited,vector<int> &pathVisited,
vector<vector<int>> &adj){
        visited[i]=1;
        pathVisited[i]=1;
        for(auto nei:adj[i]){
            if(!visited[nei]){
                if(hasCycle(nei,visited,pathVisited,adj))	return true;
            }
            else if(pathVisited[nei]==1)	return true;
        }
        pathVisited[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(hasCycle(i,visited,pathVisited,adj))	return false;
            }
        }
        return true;
    }
};
