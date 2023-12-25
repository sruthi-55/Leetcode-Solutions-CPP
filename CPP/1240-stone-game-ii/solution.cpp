class Solution {
public:
    int solve(int i,int M,bool isAlice,vector<int> &piles,vector<vector<vector<int>>> &dp){
        int n=piles.size();
        if(i>=n)    return 0;

        if(dp[i][M][isAlice]!=-1)   return dp[i][M][isAlice];

        int ans = isAlice ? -1 : 1e9;
        int stones = 0;
        for(int X=1; X <= min(n-i,2*M); X++){
            stones += piles[i+X-1];
            if(isAlice)
                ans = max(ans, stones + solve(i+X, max(M,X), !isAlice,piles,dp) );
            else    ans = min(ans, solve(i+X, max(M,X), !isAlice,piles,dp) );
        }
        return dp[i][M][isAlice] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(0,1,1,piles,dp);
    }
};
