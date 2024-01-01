class Solution {
public:
    int solve(int i,int rem,vector<int> &slices,vector<vector<int>> &dp){
        if(rem==0)    return 0;
        if(i>=slices.size())    return 0;
        
        if(dp[i][rem]!=-1)  return dp[i][rem];
        int take = slices[i]+solve(i+2,rem-3,slices,dp);
        int notTake = solve(i+1,rem,slices,dp);
        return dp[i][rem] = max(take,notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)    temp1.push_back(slices[i]);
            if(i!=n-1)  temp2.push_back(slices[i]);
        }
        vector<vector<int>> dp1(500,vector<int>(500,-1));
        int excludeFirst = solve(0,n,temp1,dp1);
        vector<vector<int>> dp2(500,vector<int>(500,-1));
        int excludeLast = solve(0,n,temp2,dp2);
        return max(excludeFirst,excludeLast);
    }
};
