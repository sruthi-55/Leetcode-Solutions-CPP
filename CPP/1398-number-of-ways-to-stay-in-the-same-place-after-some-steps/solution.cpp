class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int steps,int n,vector<vector<int>> &dp){
        if(i<0 || i>=n) return 0;
        if(steps==0)    return i==0;

        if(dp[i][steps]!=-1)    return dp[i][steps];

        //move right
        int right = solve(i+1,steps-1,n,dp);
        //move left
        int left = solve(i-1,steps-1,n,dp);
        //stay
        int stay = solve(i,steps-1,n,dp);
        return dp[i][steps]= ((right+left)%mod+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        int n=arrLen;
        vector<vector<int>> dp(n+1,vector<int>(steps+1,-1));
        return solve(0,steps,n,dp);
    }
};
