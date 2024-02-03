class Solution {
public:
    int solve(int i, vector<int>&arr,int k,vector<int> &dp){
        int n=arr.size();
        if(i>=n)    return 0;

        if(dp[i]!=-1)   return dp[i];
        
        int maxi=-1e9;
        int ans = -1e9;
        for(int j=i; j<n && j-i+1<=k; j++){
            maxi = max(maxi,arr[j]);
            ans = max(ans, (j-i+1)*maxi + solve(j+1,arr,k,dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0, arr,k,dp);
    }
};
