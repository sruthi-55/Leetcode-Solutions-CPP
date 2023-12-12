class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis=it.first;
            int node=it.second;
            for(auto nei:adj[node]){
                int neiNode=nei.first;
                int weight= nei.second;
                if(dis+weight<dist[neiNode]){
                    dist[neiNode]=dis+weight;
                    pq.push({dis+weight,neiNode});
                }
            }
        }

        int maxi=INT_MIN;
        bool isReachable=true;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                isReachable=false;
                break;
            }   
            maxi=max(maxi,dist[i]);
        }
        if(isReachable) return maxi;
        else    return -1;
    }
};
