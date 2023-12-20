class Solution {
public: 
    int solve(int i,int canBuy,int k,vector<int> &prices,
    vector<vector<vector<int>>> &dp){
        if(k==0)    return 0;
        if(i==prices.size()-1){
            if(canBuy)  return 0;
            else    return prices[i];
        }  

        if(dp[i][canBuy][k]!=-1)    return dp[i][canBuy][k];
        int profit = 0;
        if(canBuy){
            int buy = -prices[i] + solve(i+1,0,k,prices,dp);
            int notBuy = solve(i+1,1,k,prices,dp);
            profit = max(buy,notBuy);
        } 
        if(!canBuy){
            int sell = prices[i] + solve(i+1,1,k-1,prices,dp);
            int notSell = solve(i+1,0,k,prices,dp);
            profit = max(sell,notSell);
        }
        return dp[i][canBuy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};
