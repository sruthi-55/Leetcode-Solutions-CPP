class Solution {
public:
    bool dfs(int i,vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathVisited,
    vector<int> &safeNodes){
        visited[i]=1;
        pathVisited[i]=1;
        for(auto nei:adj[i]){
            if(!visited[nei]){
                if(dfs(nei,adj,visited,pathVisited,safeNodes)==false)   return false;
            }
            else if(pathVisited[nei])    return false;
        }

        pathVisited[i]=0;
        safeNodes.push_back(i);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> safeNodes;
        vector<int> visited(n,0),pathVisited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,pathVisited,safeNodes);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
