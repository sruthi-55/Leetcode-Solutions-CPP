class Solution {
public:
    bool solve(int i,vector<int> &dp){
        if(i<=0)    return 0;

        if(dp[i]!=-1)   return dp[i];

        for(int s=1; s*s<=i; s++){
            if(!solve(i-s*s,dp))    return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
