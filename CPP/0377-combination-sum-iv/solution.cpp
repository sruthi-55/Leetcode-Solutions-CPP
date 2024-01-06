class Solution {
public:
    int solve(int i,int target, vector<int> &nums,vector<vector<int>> &dp){
        if(i==nums.size())  return 0;
        if(target==0)   return 1;
        if(target<0)    return 0;

        if(dp[i][target]!=-1)   return dp[i][target];

        int take = solve(0,target-nums[i],nums,dp);
        int notTake = solve(i+1,target,nums,dp);
        
        return dp[i][target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target, nums,dp);
    }
};
