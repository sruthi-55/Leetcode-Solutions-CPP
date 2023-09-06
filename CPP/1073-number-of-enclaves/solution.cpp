class Solution {
public:
    void dfs(int nodeI,int nodeJ,vector<vector<int>> &vis,vector<vector<int>> &grid,int n,int m){
        vis[nodeI][nodeJ]=1;
        int dI[4]={1,0,-1,0};
        int dJ[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int neiI=nodeI+dI[i];
            int neiJ=nodeJ+dJ[i];
            if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<m 
            && !vis[neiI][neiJ] && grid[neiI][neiJ]==1){
                dfs(neiI,neiJ,vis,grid,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        dfs(i,j,vis,grid,n,m);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }  
            }
        }
        return count;
    }
};
