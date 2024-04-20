class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<int>>& land, int &xS,int &yS,int &xL, int &yL){
        int n=land.size(),m=land[0].size(); 
        visited[i][j]=1;
        xS = min(xS,i);
        xL = max(xL,i);
        yS = min(yS,j);
        yL = max(yL,j);

        int dX[4] = {0,1,0,-1};
        int dY[4] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nI = i + dX[k];
            int nJ = j + dY[k];
            if(nI>=0 && nJ>=0 && nI<n && nJ<m && land[nI][nJ]==1 && !visited[nI][nJ]){
                dfs(nI,nJ,visited,land,xS,yS,xL,yL);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !visited[i][j]){
                    int xS=i,yS=j,xL=i,yL=j;
                    dfs(i,j,visited,land,xS,yS,xL,yL);
                    res.push_back({xS,yS,xL,yL});
                }
            }
        }
        return res;
    }
};
