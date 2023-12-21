class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int a,int l,int n,vector<vector<vector<int>>> &dp){
        if(i==n)    return 1;

        if(dp[i][a][l]!=-1) return dp[i][a][l];
        int present = solve(i+1,a,0,n,dp);
        int absent = 0;
        if(a<1) absent = solve(i+1,a+1,0,n,dp);
        int late = 0;
        if(l<2) late = solve(i+1,a,l+1,n,dp);

        long long ans = present + absent;
        ans += late;
        return dp[i][a][l] = (ans)%mod;
    }
    int checkRecord(int n) {
        //a - 0,1
        //l - 0,1,2
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,0,n,dp);
    }
};
