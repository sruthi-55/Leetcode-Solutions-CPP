class Solution {
public:
    int solve(int target,vector<int> &dp){
        if(target==0)   return 0;

        if(dp[target]!=-1)  return dp[target];

        int ans = INT_MAX;
        for(int i=1;i*i<=target;i++){
            int take = 1+solve(target-i*i,dp);
            ans = min(take,ans);
        }
        return dp[target] = ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
