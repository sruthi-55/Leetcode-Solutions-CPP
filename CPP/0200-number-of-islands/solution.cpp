class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>> &grid){
        int n=grid.size(),m=grid[0].size();
        visited[i][j]=1;
        int dI[4]={-1,0,1,0};
        int dJ[4]={0,1,0,-1};
        for(int k=0;k<=3;k++){
            int neiI=i+dI[k];
            int neiJ=j+dJ[k];
            if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<m && 
                !visited[neiI][neiJ] && grid[neiI][neiJ]=='1'){
                    dfs(neiI,neiJ,visited,grid);
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        //n rows, m columns
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    
                    dfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};
