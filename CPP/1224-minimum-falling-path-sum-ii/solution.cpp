class Solution {
public:
    int solve(int row,int prevCol,vector<vector<int>> &grid,vector<vector<int>> &dp){
        int n=grid.size(),m=grid[0].size();
        if(row==n-1){
            int mini = 1e9;
            for(int i=0;i<m;i++){
                if(i!=prevCol)  
                    mini=min(mini,grid[n-1][i]);
            }
            return mini;
        }

        if(prevCol!=-1 && dp[row][prevCol]!=-1)    return dp[row][prevCol];

        int ans = 1e9;
        for(int i=0;i<m;i++){
            if(i!=prevCol){
                ans = min(ans,grid[row][i]+solve(row+1,i,grid,dp));
            }
        }
        
        if(prevCol==-1) return ans;
        return dp[row][prevCol] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,-1,grid,dp);
    }
};
