class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj){
        vis[i]=1;
        for(auto nei:adj[i]){
            if(!vis[nei]){
                dfs(nei,vis,adj);
            }
        }
    }
    void bfs(int i,vector<int> &vis,vector<vector<int>> &adj){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(auto nei:adj[node]){
                if(!vis[nei]){
                    q.push(nei);
                    vis[nei]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int V=isConnected.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                count++;
            }
        }
        return count;
    }
};
