class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int ind, string &s,vector<int> &visited,vector<vector<int>> &dp){
        if(ind==s.size())   return 1;

        if(dp[i][ind]!=-1)  return dp[i][ind];

        long long int ans = 0;
        if(s[ind]=='I'){
            for(int j=i+1;j<=s.size();j++){
                if(!visited[j]){
                    visited[j]=1;
                    ans = (ans+solve(j,ind+1,s,visited,dp)%mod)%mod;
                    visited[j]=0;
                }
            }
        }
        else{
            for(int j=0;j<i;j++){
                if(!visited[j]){
                    visited[j]=1;
                    ans = (ans+solve(j,ind+1,s,visited,dp)%mod)%mod;
                    visited[j]=0;
                }
            }
        }
        return dp[i][ind] = ans%mod;
    }
    int numPermsDISequence(string s) {
        int n=s.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> visited(n+1,0);
        int ans = 0;
        for(int i=0;i<=n;i++){
            visited[i]=1;
            ans = (ans+solve(i,0, s,visited,dp)%mod)%mod;
            visited[i]=0;
        }
        return ans;
    }
};
