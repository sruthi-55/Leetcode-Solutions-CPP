class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return false;
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)   return false;

        int k = totalSum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));

        for(int i=0;i<n;i++)    dp[i][0]=true;
        if(nums[0]<=k)  dp[0][nums[0]]=true;  

        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target>=nums[i]) take = dp[i-1][target-nums[i]];
                dp[i][target]= take || notTake;
            }
        }
        return dp[n-1][k];
    }
};
