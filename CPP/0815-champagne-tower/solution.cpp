class Solution {
public:
    double solve(int i,int j, int poured,vector<vector<double>> &dp){
        if(i<0 || j<0 || j>i)   return 0.0;
        if(i==0 && j==0)    return poured;

        if(dp[i][j]!=-1)    return dp[i][j];

        double left = solve(i-1,j-1, poured,dp);
        double right = solve(i-1,j, poured,dp);

        double ans = 0;
        if(left>=1) ans+=(left-1)/2.0;
        if(right>=1)    ans+=(right-1)/2.0;

        return dp[i][j] = ans;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_row+1,-1));
        return min(1.0,solve(query_row,query_glass, poured,dp));
    }
};
