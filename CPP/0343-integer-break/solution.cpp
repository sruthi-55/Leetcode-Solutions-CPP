class Solution {
public:
    //n=5
    //4,3,2,1   sum=5
    //pick items which sum to 5
    //Multiply value of each picked item and maximize this product
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return dfs(n-1,n,dp);
    }
    int dfs(int num,int sum,vector<vector<int>> &dp){
        if(num==1)  return 1;
        if(dp[num][sum]!=-1)    return dp[num][sum];

        int notPick = dfs(num-1,sum,dp);
        int pick=0;
        if(sum>=num)   pick=num*dfs(num,sum-num,dp);
        
        return dp[num][sum] = max(pick,notPick);
    }
};

