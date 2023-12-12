class Solution {
public:
    void dfs(int nodeI,int nodeJ,vector<vector<int>> &vis,vector<vector<char>>& board,int n, int m){
        vis[nodeI][nodeJ]=1;
        int dI[4]={1,0,-1,0};
        int dJ[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int neiI=nodeI+dI[i];
            int neiJ=nodeJ+dJ[i];
            if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<m 
            && !vis[neiI][neiJ] && board[neiI][neiJ]=='O'){
                dfs(neiI,neiJ,vis,board,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!vis[i][j] && board[i][j]=='O'){
                        dfs(i,j,vis,board,n,m);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
