class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(i==n-1){
                    dp[n-1][j]=triangle[n-1][j];
                    continue;
                }
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};


