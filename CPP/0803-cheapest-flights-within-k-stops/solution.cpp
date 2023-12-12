class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();  q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stops>k) continue;
            for(auto nei:adj[node]){
                int neiNode = nei.first;
                int weight = nei.second;
                if(stops<=k && dis+weight<dist[neiNode]){
                    dist[neiNode]=dis+weight;
                    q.push({stops+1,{neiNode,dis+weight}});
                }
            }
        }

        if(dist[dst]==1e9)  return -1;
        return dist[dst];
    }
};
