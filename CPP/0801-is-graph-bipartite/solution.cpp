class Solution {
public:
    bool bfs(int src,vector<vector<int>>& adj,vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nei:adj[node]){
                if(color[nei]==-1){
                    q.push(nei);
                    color[nei]=!color[node];
                }
                else if(color[nei]==color[node])	return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        if(adj.size()==0)    return false;
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(bfs(i,adj,color)==false) return false;
        }
        return true;
    }
};
