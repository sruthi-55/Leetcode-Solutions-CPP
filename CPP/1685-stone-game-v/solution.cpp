class Solution {
public: 
    int solve(int l,int r,vector<int> &stoneValue,vector<vector<int>> &dp){
        if(l>r) return 0;
        
        if(dp[l][r]!=-1)    return dp[l][r];

        int totalSum = 0;
        for(int i=l;i<=r;i++)   totalSum+=stoneValue[i];

        int ans = 0;
        int stones=0;
        for(int i=l;i<r;i++){
            stones += stoneValue[i];
            int leftSum = stones;
            int rightSum = totalSum - leftSum;

            if(leftSum > rightSum){
                ans = max(ans, rightSum + solve(i+1,r,stoneValue,dp));
            }
            else if(rightSum > leftSum)   
                ans = max(ans, leftSum + solve(l,i,stoneValue,dp));
            else    
                ans = max(ans, rightSum + max(
                        solve(i+1,r,stoneValue,dp),
                        solve(l,i,stoneValue,dp)));
            
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,stoneValue,dp);
    }
};
