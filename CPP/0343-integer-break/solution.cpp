class Solution {
public:
    int solve(int target,vector<int> &dp){
        if(target==0)   return 1;

        if(dp[target]!=-1)  return dp[target];
        
        int ans=0;
        for(int i=1;i<=target;i++){
            ans = max(ans, i*solve(target-i,dp) );
        }
        return dp[target] = ans;
    }
    int integerBreak(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;

        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

