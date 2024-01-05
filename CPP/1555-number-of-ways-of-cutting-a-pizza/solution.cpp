class Solution {
public:
int mod = 1e9+7;
    int solve(int i,int j,int k, vector<string> &pizza,vector<vector<int>> &arr,    vector<vector<vector<int>>> &dp){
        if(arr[i][j]<k) return 0;
        if(k==1){
            if(arr[i][j]>=1)    return 1;
            return 0;
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int ans=0;
        //horizontal cut
        for(int cut = i+1;cut<pizza.size();cut++){
            int belowApp = arr[cut][j];
            int aboveApp = arr[i][j] - belowApp;
            
            if(aboveApp>=1 && belowApp>=k-1)
                ans = (ans+solve(cut,j,k-1,pizza,arr,dp))%mod;
        }

        //vertical cut
        for(int cut=j+1;cut<pizza[0].size();cut++){
            int rightApp = arr[i][cut];
            int leftApp = arr[i][j] - rightApp;
            
            if(leftApp>=1 && rightApp>=k-1)
                ans = (ans+solve(i,cut,k-1,pizza,arr,dp))%mod;
        }
        return dp[i][j][k] = ans%mod;
    }
    int ways(vector<string>& pizza, int k) {
        int n=pizza.size(),m=pizza[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(pizza[i][j]=='A')    arr[i][j]=1;
            
                if(j<m-1)    arr[i][j] += arr[i][j+1];
                if(i<n-1)   arr[i][j] += arr[i+1][j];
                if(i<n-1 && j<m-1)  arr[i][j] -= arr[i+1][j+1];
            }
        }

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(0,0,k,pizza,arr,dp);
    }
};
