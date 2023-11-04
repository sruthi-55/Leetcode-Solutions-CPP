#define ll long long int
class Solution {
public:
    ll INF = LLONG_MAX;
    ll solve(ll i,ll canSkip,vector<int>& nums, int k,vector<vector<ll>> &dp){
        if(canSkip<0)  return INF;
        if(i>=nums.size())  return 0;
        
        if(dp[i][canSkip]!=-1)  return dp[i][canSkip];
        ll take = max(0,k-nums[i]) + solve(i+1,2,nums,k,dp);
        ll notTake = solve(i+1,canSkip-1,nums,k,dp);
        return dp[i][canSkip]=min(take,notTake);
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<vector<ll>> dp(nums.size()+1,vector<ll>(4,-1));
        return solve(0,2,nums,k,dp);
    }
};
