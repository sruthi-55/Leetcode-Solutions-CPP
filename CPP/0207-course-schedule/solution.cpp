class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
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
        int count=0;
        while(!q.empty()){
            int node=q.front(); q.pop();
            count++;
            for(auto nei:adj[node]){
                inDegree[nei]--;
                if(inDegree[nei]==0)    q.push(nei);
            }
        }
        return count==n ? true : false;
    }
};
