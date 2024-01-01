class Solution {
public:
int mod = 1e9+7;
    int solve(int people,int p,int scheme, 
    int n,int minProfit,vector<int>& group,vector<int>& profit,vector<vector<vector<int>>> &dp){
        if(people > n)    return 0;
        if(scheme==profit.size()){
            if(p>=minProfit)    return 1;
            else    return 0;    
        }
            
        if(dp[people][p][scheme]!=-1)   return dp[people][p][scheme];

        //do it
        int doIt = solve(people+group[scheme],min(minProfit,p+profit[scheme]),scheme+1, 
        n,minProfit,group,profit,dp)%mod;
        //not do it
        int notDoIt = solve(people,p,scheme+1, n,minProfit,group,profit,dp)%mod;

        return dp[people][p][scheme] = (doIt + notDoIt)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(minProfit+1,
                vector<int>(profit.size()+1,-1)));
        return solve(0,0,0, n,minProfit,group,profit,dp)%mod;
    }
};



