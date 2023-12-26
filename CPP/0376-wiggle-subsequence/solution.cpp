class Solution {
public:
    int helper(int prev,bool isPosDiff,int n,vector<int>& nums,
    vector<vector<int>> &dp){        
        if(prev == n-1)  return 0;
        if(dp[prev][isPosDiff] != -1) return dp[prev][isPosDiff];
        
        int ans = 0;
        
        // we need positive diff.
        if(isPosDiff)  {
            if(nums[prev+1] > nums[prev])
                ans = max(ans, 1 + helper(prev+1,!isPosDiff, n,nums,dp));
            else
                ans = max(ans, helper(prev+1,isPosDiff, n,nums,dp));
        }
        // we need negative diff
        else{
            if(nums[prev+1] < nums[prev])
                ans = max(ans, 1 + helper(prev+1,!isPosDiff, n,nums,dp));
            else
                ans = max(ans, helper(prev+1,isPosDiff, n,nums,dp));
        }
        
        return dp[prev][isPosDiff] = ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        // by taking positive diff
        ans = max(ans, helper(0,true,n,nums,dp));
        
        // by taking negative diff
        ans = max(ans, helper(0,false,n,nums,dp));
        
        //included first ele initially
        return ans+1;
    }
};
