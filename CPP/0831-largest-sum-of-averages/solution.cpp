class Solution {
public:
    double solve(int prev,int k, vector<int>&nums,vector<vector<double>> &dp){
        if(prev==nums.size()-1)   return 0.0;
        if(k==0)    return -1e9;
        
        if(prev!=-1 && dp[prev][k]!=-1) return dp[prev][k];

        double sum=0;
        double ans=0;
        for(int j=prev+1;j<nums.size();j++){
            sum+=nums[j];
            ans = max(ans, (double)sum/(j-prev)+  solve(j,k-1, nums,dp));
        }

        if(prev==-1)    return ans;
        return dp[prev][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>> dp(n+1,vector<double>(k+1,-1));
        return solve(-1,k, nums,dp);
    }
};
