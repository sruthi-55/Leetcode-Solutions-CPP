class Solution {
public:
    int solve(int i,vector<int> &dp){
        if(i==0)    return 0;
        if(i==1)    return 1;

        if(dp[i]!=-1)   return dp[i];

        if(i%2==0)  return dp[i] = solve(i/2,dp);
        return dp[i] = 1+solve(i/2,dp);
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        vector<int> dp(n+1,-1);
        for(int i=0;i<=n;i++){
            int bits=0;
            if(dp[i]!=-1)   bits = dp[i];
            else    bits = solve(i,dp);
            ans.push_back(bits);
        }
        return ans;
    }
};
