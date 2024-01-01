class Solution {
public:
    int mod = 1e9+7;
    long solve(int songs,int uniqueSongs, int goal,int n,int k,vector<vector<long>> &dp){
        if(songs==goal){
            if(uniqueSongs==n)  return 1;
            return 0;
        }
        if(uniqueSongs>n)   return 0;

        if(dp[songs][uniqueSongs]!=-1)  return dp[songs][uniqueSongs];

        long op1=0,op2=0;
        //play unique song
        if(uniqueSongs<=n)
            op1 = ((n-uniqueSongs)* solve(songs+1,uniqueSongs+1,goal,n,k,dp)%mod)%mod;
        //repeat song
        if(k<=uniqueSongs)
            op2 = ((uniqueSongs-k) * solve(songs+1,uniqueSongs,goal,n,k,dp)%mod)%mod;
            
        return dp[songs][uniqueSongs] = (op1+op2)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(goal+1,vector<long>(n+1,-1));
        return solve(0,0, goal,n,k,dp);
    }
};
