class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totTime=0;
        int rottened=0;
        int oranges=0;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)  
                    oranges++;
                else if(grid[i][j]==2)
                    q.push({i,j}),oranges++;
            }
        } 
        while(!q.empty()){
            int k=q.size();
            rottened+=k;
            for(int I=0;I<k;I++){
                int nodeI=q.front().first;
                int nodeJ=q.front().second;
                q.pop();
                int dI[4]={+1,0,-1,0};
                int dJ[4]={0,-1,0,+1};
                for(int i=0;i<4;i++){
                    int neiI=nodeI+dI[i];
                    int neiJ=nodeJ+dJ[i];
                    if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<m && 
                    grid[neiI][neiJ]==1){
                        grid[neiI][neiJ]=2;
                        q.push({neiI,neiJ});
                    }
                }
            }
            if(!q.empty())  totTime++;
        }
        return oranges == rottened ? totTime : -1;
    }
};
