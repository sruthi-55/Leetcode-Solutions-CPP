class Solution {
public:
    double solve(int r,int c,int k, int n,vector<vector<vector<double>>> &dp){
        if(r<0 || c<0 || r>n-1 || c>n-1)    return 0;
        if(k==0)    return 1;

        if(dp[r][c][k]!=-1) return dp[r][c][k];

        double ans = 0;
        int dx[8] = {-2,-1,1,2,2,1,-1,-2};
        int dy[8] = {1,2,2,1,-1,-2,-2,-1};
        for(int i=0;i<8;i++){
            int nR = r+dx[i];
            int nC = c+dy[i];
            ans += solve(nR,nC,k-1, n,dp);
        }
        return dp[r][c][k] = ans/8.0;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(row,col,k, n,dp);
    }
};
