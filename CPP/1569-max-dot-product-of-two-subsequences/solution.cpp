class Solution {
public:
    int solve(int i,int j,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
        if(i==nums1.size() || j==nums2.size())  return -1e9;

        if(dp[i][j]!=-1)    return dp[i][j];
        int val=nums1[i]*nums2[j];
        //take from nums1,nums2 and continue
        int takeIJ = val+ solve(i+1,j+1,nums1,nums2,dp);
        //take from nums1 and skip nums2
        int takeI = solve(i,j+1,nums1,nums2,dp);
        //take from nums2 and skip nums1
        int takeJ = solve(i+1,j,nums1,nums2,dp);
        //not take both
        int notTake = solve(i+1,j+1,nums1,nums2,dp);
        return dp[i][j]= max({takeIJ,takeI,takeJ,val,notTake});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(0,0,nums1,nums2,dp);
    }
};
