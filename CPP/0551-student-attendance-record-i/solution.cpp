class Solution {
public:
    bool solve(int i,int a,int l,string &s,vector<vector<vector<int>>> &dp){
        if(a==2)    return false;
        if(l==3)    return false;
        if(i==s.size())    return true;

        if(dp[i][a][l]!=-1)     return dp[i][a][l];

        bool ans;
        if(s[i]=='A')   ans = solve(i+1,a+1,0,s,dp);
        else if(s[i]=='L')  ans = solve(i+1,a,l+1,s,dp);
        else    ans = solve(i+1,a,0,s,dp);
        return dp[i][a][l] = ans;
    }
    bool checkRecord(string s) {
        int n=s.size();
        //a - 0,1
        //l - 0,1,2
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(4,-1)));
        return solve(0,0,0,s,dp);
    }
};
