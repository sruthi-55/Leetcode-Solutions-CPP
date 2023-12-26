class Solution {
public:
    int solve(int i,vector<int> &dp){
        if(i==0)    return 1;
        if(i==1)    return 1;

        if(dp[i]!=-1)   return dp[i];

        int ans = 0;
        for(int root=1;root<=i;root++){
            int left = root-1;
            int right = i-root;
            ans += solve(left,dp)*solve(right,dp);
        }
        return dp[i] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
