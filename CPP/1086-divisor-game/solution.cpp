class Solution {
public:
    bool solve(int i,vector<int> dp){
        if(i<=1)    return false;
        if(dp[i]!=-1)   return dp[i];

        for(int x=1;x<i;x++){
            if(i%x==0){
                bool bob = solve(i-x,dp);
                return dp[i]=!bob;
            }
        }
        return dp[i]=0;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
