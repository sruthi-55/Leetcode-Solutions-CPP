class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==s1.size() || j==s2.size())    return 0;

        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = INT_MIN;
        if(s1[i]==s2[j])    ans = 1+solve(i+1,j+1,s1,s2,dp);
        else{
            ans = max(ans,max(solve(i,j+1,s1,s2,dp),solve(i+1,j,s1,s2,dp)));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(0,0,s1,s2,dp);
    }
};
