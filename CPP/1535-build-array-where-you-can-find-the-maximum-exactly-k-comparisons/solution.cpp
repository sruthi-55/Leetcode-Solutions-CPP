class Solution {
public:
    int mod = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        if(m<k) return 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solve(0,0,0,n,m,k,dp)%mod;
    }
    int solve(int idx,int searchCost,int maxSoFar,int n,int m, int k, vector<vector<vector<int>>> &dp){
        if(idx==n){
            if(searchCost==k)   return 1;
            return 0;
        }
        if(dp[idx][searchCost][maxSoFar]!=-1)   return dp[idx][searchCost][maxSoFar];
        int res=0;
        for(int next=1;next<=m;next++){
            if(next>maxSoFar){
                res=(res+solve(idx+1,searchCost+1,next,n,m,k,dp))%mod;
            }
            else{
                res=(res+solve(idx+1,searchCost,maxSoFar,n,m,k,dp))%mod;
            }
        }
        return dp[idx][searchCost][maxSoFar]=res%mod;
    }
};



