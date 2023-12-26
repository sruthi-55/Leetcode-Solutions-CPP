class Solution {
public:
    int solve(int i,int canBuy,vector<int> &prices,int fee,
    vector<vector<int>> &dp){
        if(i==prices.size())    return 0;

        if(dp[i][canBuy]!=-1)   return dp[i][canBuy];
        int ans = INT_MIN;
        if(canBuy){
            int buy = -prices[i]-fee+solve(i+1,!canBuy,prices,fee,dp);
            int notBuy = solve(i+1,canBuy,prices,fee,dp);
            ans = max(buy,notBuy);
        }
        else{
            int sell = prices[i]+solve(i+1,!canBuy,prices,fee,dp);
            int notSell = solve(i+1,canBuy,prices,fee,dp);
            ans = max(sell,notSell);
        }
        return dp[i][canBuy] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }
};
