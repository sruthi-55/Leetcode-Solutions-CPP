class Solution {
public:
    int helper(int i,int rem,vector<int> &cost,vector<int> &time,vector<vector<int>> &dp){
        if(rem<=0)  return 0;
        if(i==cost.size())    return 1e9;

        if(dp[i][rem]!=-1)  return dp[i][rem];
        int paint = cost[i]+ helper(i+1,rem-1-time[i],cost,time,dp);
        int not_paint = helper(i+1,rem,cost,time,dp);

        return dp[i][rem]= min(paint,not_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        //(idx,no_of_walls_remaining,cost,time,dp);
        return helper(0,n,cost,time,dp);
    }
};



