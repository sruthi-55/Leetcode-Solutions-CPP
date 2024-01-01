class Solution {
public:
    int solve(int i,int swappedBefore, 
    vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
        if(i>=nums1.size()) return 0;

        if(dp[i][swappedBefore]!=-1)    return dp[i][swappedBefore];

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        if(swappedBefore)   swap(prev1,prev2);

        int ans = 1e9;  
        if(nums1[i]>prev1 && nums2[i]>prev2)
            ans = solve(i+1,0,nums1,nums2,dp);

        if(nums1[i]>prev2 && nums2[i]>prev1)
            ans = min(ans, 1+solve(i+1,1,nums1,nums2,dp) );
        return dp[i][swappedBefore] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(1,0, nums1,nums2,dp);
    }
};
