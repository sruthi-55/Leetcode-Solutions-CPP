class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e6));
        dist[0][0]=0;
        //{effort,{X,Y}}
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();   pq.pop();
            int effort=it.first;
            int nodeI=it.second.first;
            int nodeJ=it.second.second;
            if(nodeI==n-1 && nodeJ==m-1)    return effort;


            int dI[4]={-1,0,1,0};
            int dJ[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int neiI=nodeI+dI[i];
                int neiJ=nodeJ+dJ[i];
                if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<m ){
                    int newEffort = max(effort,abs(heights[neiI][neiJ]-heights[nodeI][nodeJ]));
                    if(newEffort < dist[neiI][neiJ]){
                        dist[neiI][neiJ]=newEffort;
                        pq.push({newEffort,{neiI,neiJ}});
                    }
                }
            }
        }
        return -1;
    }
};
