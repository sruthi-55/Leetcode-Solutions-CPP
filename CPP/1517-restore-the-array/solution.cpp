class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int k,string &s,vector<int> &dp){
        if(s[i]=='0') return 0;
        if(i==s.size()) return 1;

        if(dp[i]!=-1)   return dp[i];

        long num=0;
        int ans = 0;
        for(int j=i;j<s.size();j++){
            num = num*10+(s[j]-'0');
            if(num<=k)  ans = (ans+solve(j+1,k,s,dp)%mod)%mod;
            else    break;
        }
        return dp[i] = ans%mod;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(),-1);
        return solve(0,k,s,dp);
    }
};
