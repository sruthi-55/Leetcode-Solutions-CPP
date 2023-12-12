class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0)   return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        //{dist,{x,y}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            auto it= q.front(); q.pop();
            int dis = it.first;
            int nodeI = it.second.first;
            int nodeJ = it.second.second;
            if(nodeI==n-1 && nodeJ==n-1)    return dis+1;

            for(int dI=-1;dI<=1;dI++){
                for(int dJ=-1;dJ<=1;dJ++){
                    int neiI= nodeI+dI;
                    int neiJ= nodeJ+dJ;

                    if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<n && 
                    grid[neiI][neiJ]==0 && dis+1<dist[neiI][neiJ]){
                        dist[neiI][neiJ]=1+dis;
                        q.push({dis+1,{neiI,neiJ}});
                    }
                }
            }
        }
        return -1;
    }
};
