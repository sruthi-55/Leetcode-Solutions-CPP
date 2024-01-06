class Solution {
public:
    int solve(int i,int neiC,int target, vector<int>& houses, vector<vector<int>>& cost, int m, int n,vector<vector<vector<int>>> &dp){
        if(target<0)    return 1e9;
        if(i==houses.size()){
            if(target==0)   return 0;  
            return 1e9;
        }

        if(neiC!=-1 && dp[i][neiC][target]!=-1) return dp[i][neiC][target];

        int ans = 1e9;
        if(houses[i]==0){
            for(int col=1;col<=n;col++){
                if(col==neiC)
                    ans = min(ans, cost[i][col-1] + 
                    solve(i+1,neiC,target, houses,cost,m,n,dp));
                else    
                    ans = min(ans, cost[i][col-1] + 
                    solve(i+1,col,target-1, houses,cost,m,n,dp));
            }
        }
        else    
            ans = min(ans, solve(i+1,houses[i],
            houses[i]==neiC?target:target-1, houses,cost,m,n,dp));


        if(neiC==-1)    return ans;
        return dp[i][neiC][target] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int ans = solve(0,-1,target, houses,cost,m,n,dp);
        if(ans>=1e9)    return -1;
        return ans;
    }
};

