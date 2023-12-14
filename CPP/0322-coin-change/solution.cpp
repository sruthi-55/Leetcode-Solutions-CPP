class Solution {
public:
    int solve(int i,int target,vector<int> &coins,vector<vector<int>> &dp){
        if(target==0)   return 0;
        if(i==0){
            if(target%coins[0]==0) return target/coins[0];
            return 1e9;
        }

        if(dp[i][target]!=-1)   return dp[i][target];
        int notTake = solve(i-1,target,coins,dp);
        int take = 1e9;
        if(target>=coins[i])    take = 1 + solve(i,target-coins[i],coins,dp);
        return dp[i][target] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        if(ans==1e9)    return -1;
        return ans;
    }
};
