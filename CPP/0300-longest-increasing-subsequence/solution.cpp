class Solution {
public:
    int solve(int i,int prevMaxI,vector<int> &nums,vector<vector<int>> &dp){
        if(i==nums.size())  return 0;

        if(prevMaxI!=-1 && dp[i][prevMaxI]!=-1)   return dp[i][prevMaxI];

        int take = 0,notTake = 0;
        if(prevMaxI==-1 || nums[i]>nums[prevMaxI]) take = 1 + solve(i+1,i,nums,dp);
        notTake = solve(i+1,prevMaxI,nums,dp);

        if(prevMaxI==-1) return max(take,notTake);
        return dp[i][prevMaxI] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};
