class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[0][j]=matrix[0][j];
                    continue;
                }
                int up = matrix[i][j] + dp[i-1][j];
                int leftD = 1e9;
                if(j>0) leftD =  matrix[i][j] + dp[i-1][j-1];
                int rightD = 1e9;
                if(j+1<m)   rightD = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(up,min(leftD,rightD));
            }
        }
        int minSum = 1e9;
        for(int j=0;j<m;j++){
            minSum = min(minSum,dp[n-1][j]);
        }
        return minSum;
    }
};
