class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int nodeI=q.front().first.first;
            int nodeJ=q.front().first.second;
            int dist=q.front().second;
            q.pop();

            int dI[4]={1,0,-1,0};
            int dJ[4]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int neiI=nodeI+dI[i];
                int neiJ=nodeJ+dJ[i];
                if(neiI>=0 && neiJ>=0 && neiI<m && neiJ<n
                && !vis[neiI][neiJ] && mat[neiI][neiJ]==1){
                    q.push({{neiI,neiJ},dist+1});
                    vis[neiI][neiJ]=1;
                    ans[neiI][neiJ]=dist+1;
                }
            }
        }
        return ans;
    }
};
