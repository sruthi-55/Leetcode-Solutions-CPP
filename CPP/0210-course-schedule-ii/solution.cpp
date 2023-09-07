class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[1]].push_back(e[0]);
        }

        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto nei:adj[i]){
                inDegree[nei]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)  q.push(i);
        }
        vector<int> topoSort;
        while(!q.empty()){
            int node=q.front(); q.pop();
            topoSort.push_back(node);
            for(auto nei:adj[node]){
                inDegree[nei]--;
                if(inDegree[nei]==0)    q.push(nei);
            }
        }
        if(topoSort.size()==n)  return topoSort;
        return {}; 
    }
};
