class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int j,int k, int m,int n,vector<vector<vector<int>>> &dp){
        if(k<0)    return 0;
        if(i<0 || j<0 || i>m-1 || j>n-1)    return 1;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int ans = 0;
        ans = (ans+solve(i-1,j,k-1,m,n,dp)%mod)%mod;
        ans = (ans+solve(i,j-1,k-1,m,n,dp)%mod)%mod;
        ans = (ans+solve(i+1,j,k-1,m,n,dp)%mod)%mod;
        ans = (ans+solve(i,j+1,k-1,m,n,dp)%mod)%mod;

        return dp[i][j][k] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startR, int startC) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startR,startC,maxMove ,m,n,dp);
    }
};
