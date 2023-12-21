class Solution {
public:
    int solve(int i,string &s,vector<int> &dp){
        int n = s.size();
        if(i>=n) return 1;
        if(s[i]=='0') return 0;

        if(dp[i]!=-1)   return dp[i];

        int ans = 0;
        if(s[i]=='1'){
            if(i==n-1)   ans = solve(i+1,s,dp);
            else    ans = solve(i+1,s,dp) + solve(i+2,s,dp);
        }   
        else if(s[i]=='2'){
            if(i==n-1)   ans = solve(i+1,s,dp);
            else{
                int c = s[i+1]-'0';
                if(c>=0 && c<=6)   ans = solve(i+1,s,dp) + solve(i+2,s,dp);
                else  ans = solve(i+2,s,dp);
            }  
        }  
        else    ans = solve(i+1,s,dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};
