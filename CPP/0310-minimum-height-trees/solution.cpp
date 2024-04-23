class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)    return {};
        if(n==1)    return {0};
        
        vector<int> inDegree(n,0);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1){
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()){
            int sz = q.size();
            res.clear();
            for(int i=0;i<sz;i++){
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for(auto nei:adj[cur]){
                    inDegree[nei]--;
                    if(inDegree[nei]==1)
                        q.push(nei);
                }
            }
        }
        return res;
    }
};
